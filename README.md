# parkin-Rosco
Este proyecto es un sistema automatizado de gestión de parking desarrollado con Arduino Uno, diseñado para controlar el acceso y salida de vehículos, gestionar la ocupación y mostrar el estado del parking en una pantalla LCD con interfaz I2C. El sistema utiliza sensores de infrarrojos para detectar vehículos en la entrada y salida, un servomotor para controlar una barrera automática, y LEDs para indicar visualmente la disponibilidad del aparcamiento.

Características Principales
Detección de Vehículos: Mediante sensores de infrarrojos en la entrada y salida del parking.
Gestión de Ocupación: Contador de vehículos que actualiza en tiempo real el estado de ocupación en una pantalla LCD.
Control de Barrera Automática: Barrera controlada por un servomotor que se abre y cierra automáticamente al detectar un vehículo.
Indicadores LED: LED verde para mostrar disponibilidad y LED rojo para indicar que el parking está lleno.
Componentes Utilizados
Arduino Uno
2 Sensores de infrarrojos
Pantalla LCD con módulo I2C
Servomotor (para la barrera)
LEDs (rojo y verde)
Resistencias para LEDs (220Ω)
Requisitos de Software
IDE de Arduino o Eclipse con la extensión para Arduino
Librerías utilizadas: LiquidCrystal_I2C, Servo.

El sistema detecta la entrada y salida de vehículos a través de sensores infrarrojos. Según el número de vehículos dentro del parking:

La pantalla LCD muestra el número de plazas ocupadas y libres.
Los LEDs indican el estado de ocupación: verde para plazas disponibles y rojo cuando el parking está lleno.
La barrera se abre al detectar un vehículo en la entrada y se cierra tras un breve intervalo. Lo mismo ocurre para la salida.
Futuras Mejoras
Integración con una aplicación móvil para consultar el estado del parking en tiempo real.
Control de acceso mediante tarjetas RFID.
Añadir una cámara para capturar la matrícula de los vehículos.
