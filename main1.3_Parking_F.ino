#include "parking.h"

void setup() {
    inicializarParking(); // Inicializar todos los componentes
}

void loop() {
    verificarEntrada(); // Verificar si hay un vehículo en la entrada
    verificarSalida();  // Verificar si hay un vehículo en la salida
    delay(500);         // Retardo para evitar lecturas muy rápidas
}

