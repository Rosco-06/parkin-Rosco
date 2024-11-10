#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include "parking.h"
#include <Wire.h>    // Incluimos la librería Wire.h que establece la comunicación con el protocolo I2C.            
#include <LiquidCrystal_I2C.h>    // Incluimos la librería para usar la pantalla LCD con el módulo I2C.

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
Servo servo;

const int sensorEntrada = 2;
const int sensorSalida = 3;
const int ledVerde = 10;
const int ledRojo = 11;

int contadorVehiculos = 0;
const int maxVehiculos = 3; // Capacidad máxima del parking

void inicializarParking() {
    Serial.begin(9600); // Inicializar comunicación Serial
    lcd.begin(16, 2);
    lcd.backlight();
    servo.attach(9);
    servo.write(0);  // Inicializar el servomotor en la posición 0
    pinMode(sensorEntrada, INPUT);
    pinMode(sensorSalida, INPUT);
    pinMode(ledVerde, OUTPUT);
    pinMode(ledRojo, OUTPUT);

    lcd.setCursor(0,0);
    lcd.print("Iniciando");
    lcd.setCursor(0,1);
    lcd.print("parking");


    delay(5000); // Pausa para ver mensaje
    
    actualizarPantalla(); // Mostrar ocupación inicial en LCD
}

void verificarEntrada() {
    if (digitalRead(sensorEntrada) == LOW && contadorVehiculos < maxVehiculos) {
        contadorVehiculos++;

        Serial.print("Vehículo detectado en la entrada. Contador: ");
        Serial.println(contadorVehiculos);

        subirBarrera();
        actualizarPantalla();
        
        // Llama a la función para bajar la barrera después de 5 segundos
        delay(5000); // Esperar 5 segundos
        bajarBarrera();
    }
}

void verificarSalida() {
    if (digitalRead(sensorSalida) == LOW && contadorVehiculos > 0) {
        contadorVehiculos--;

        Serial.print("Vehículo detectado en la salida. Contador: ");
        Serial.println(contadorVehiculos);

        subirBarrera();
        actualizarPantalla();
        
        // Llama a la función para bajar la barrera después de 5 segundos
        delay(5000); // Esperar 5 segundos
        bajarBarrera();
    }
}

void actualizarPantalla() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ocupados: ");
    lcd.print(contadorVehiculos);
    lcd.setCursor(0, 1);
    lcd.print("Libres: ");
    lcd.print(maxVehiculos - contadorVehiculos);

    if (contadorVehiculos >= maxVehiculos) {
        digitalWrite(ledRojo, HIGH);
        digitalWrite(ledVerde, LOW);
        Serial.println("Parking lleno: LED rojo encendido, LED verde apagado.");
    } else {
        digitalWrite(ledRojo, LOW);
        digitalWrite(ledVerde, HIGH);
        Serial.println("Espacios libres: LED verde encendido, LED rojo apagado.");
    }
}

void subirBarrera() {
    Serial.println("Subiendo barrera...");
    servo.write(90);  // Ángulo para abrir la barrera
    delay(1000);      // Pausa para abrir
}

void bajarBarrera() {
    Serial.println("Bajando barrera...");
    servo.write(0);   // Ángulo para cerrar la barrera
    delay(1000);      // Pausa para cerrar
}

bool estadoBarrera() {
    return servo.read() > 0; // Retorna true si la barrera está arriba
}

int obtenerVehiculosOcupados() {
    return contadorVehiculos;
}

int obtenerEspaciosLibres() {
    return maxVehiculos - contadorVehiculos;
}



