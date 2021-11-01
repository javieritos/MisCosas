#include "AccelStepper.h"
 
// Definición del método de motor paso a paso
#define FULLSTEP 4    // Parámetros de paso completo
#define HALFSTEP 8    // Parámetros de medio paso
 
// Definir los pines del motor paso a paso. 
#define motor1Pin1  2     // Pin 1 de la placa de accionamiento del motor ULN2003 conectada al número 28BYJ48
#define motor1Pin2  3     // Pin 1 de la placa de accionamiento del motor ULN2003 conectada al número 28BYJ48
#define motor1Pin3  4    // Pin 3 de la placa de accionamiento del motor ULN2003 conectado al número 28BYJ48
#define motor1Pin4  5    // Pin 4 de la placa de accionamiento del motor ULN2003 conectada al número 28BYJ48
                                   
#define motor2Pin1  6     // Pin 2 de la placa de accionamiento del motor ULN2003 conectada al número 28BYJ48
#define motor2Pin2  7     // Pin 2 de la placa de accionamiento del motor ULN2003 conectada al número 28BYJ48
#define motor2Pin3  8     // Pin 3 de la placa de accionamiento del motor ULN2003 conectada al número 28BYJ48
#define motor2Pin4  9     // Pin 4 de la placa de accionamiento del motor ULN2003 conectada al número 28BYJ48
 
// Define dos objetos de motor paso a paso
// Motor No. 1 está configurado para operación de medio paso, motor No. 2 está configurado para operación de paso completo
AccelStepper stepper1(HALFSTEP, motor1Pin1, motor1Pin3, motor1Pin2, motor1Pin4);
AccelStepper stepper2(FULLSTEP, motor2Pin1, motor2Pin3, motor2Pin2, motor2Pin4);
 
void setup() {
  stepper1.setMaxSpeed(1000.0);    // No. 1 velocidad máxima del motor 500 
  stepper1.setAcceleration(500.0);  // No. 1 aceleración del motor 50.0
 
  stepper2.setMaxSpeed(500.0);    // La velocidad máxima del motor No. 2 es 500 
  stepper2.setAcceleration(50.0);  // No. 2 aceleración del motor 50.0
}
 
void loop() {
  if ( stepper1.currentPosition() == 0 && stepper2.currentPosition() == 0 ){
    // El motor n. ° 1 gira medio círculo
    stepper1.moveTo(20480);              
    // Motor No. 2 hace una revolución
    stepper2.moveTo(20480);  
    
  } else if ( stepper1.currentPosition() == 20480 && stepper2.currentPosition() == 20480 ){
    // El motor n. ° 1 gira medio círculo
    stepper1.moveTo(0);            
    // Motor No. 2 hace una revolución
    stepper2.moveTo(0);  
  }         
  
  stepper1.run();   // Motor No. 1 está funcionando
  stepper2.run();   // Motor No. 2 está funcionando
}
