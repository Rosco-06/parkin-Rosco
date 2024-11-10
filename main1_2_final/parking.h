#ifndef PARKING_H
#define PARKING_H

#include <Arduino.h>

void inicializarParking();        // Inicializar componentes del parking
void verificarEntrada();          // Verificar y manejar entrada de vehículos
void verificarSalida();           // Verificar y manejar salida de vehículos
void actualizarPantalla();        // Actualizar la pantalla con ocupación
void subirBarrera();              // Subir la barrera
void bajarBarrera();              // Bajar la barrera
bool estadoBarrera();             // Consultar el estado de la barrera

int obtenerVehiculosOcupados();   // Devuelve la cantidad de vehículos ocupados
int obtenerEspaciosLibres();      // Devuelve la cantidad de espacios libres

#endif
