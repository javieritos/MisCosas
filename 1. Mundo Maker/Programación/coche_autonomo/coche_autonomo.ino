#include "AccelStepper.h"

#define TRIGGER 10 //Pin de sensor Trigger
#define ECHO 11
 
// Definición del método de motor paso a paso
#define FULLSTEP 4    // Parámetros de paso completo
#define HALFSTEP 8    // Parámetros de medio paso
 
// Definir los pines del motor paso a paso. 
#define motor1Pin1  6     // Pin 1 de la placa de accionamiento del motor ULN2003 conectada al número 28BYJ48
#define motor1Pin2  7     // Pin 1 de la placa de accionamiento del motor ULN2003 conectada al número 28BYJ48
#define motor1Pin3  8    // Pin 3 de la placa de accionamiento del motor ULN2003 conectado al número 28BYJ48
#define motor1Pin4  9    // Pin 4 de la placa de accionamiento del motor ULN2003 conectada al número 28BYJ48
                                   
#define motor2Pin1  2     // Pin 2 de la placa de accionamiento del motor ULN2003 conectada al número 28BYJ48
#define motor2Pin2  3     // Pin 2 de la placa de accionamiento del motor ULN2003 conectada al número 28BYJ48
#define motor2Pin3  4     // Pin 3 de la placa de accionamiento del motor ULN2003 conectada al número 28BYJ48
#define motor2Pin4  5     // Pin 4 de la placa de accionamiento del motor ULN2003 conectada al número 28BYJ48

#define motor3Pin1  14     
#define motor3Pin2  15     
#define motor3Pin3  16     
#define motor3Pin4  17

//Constantes

const float sonido = 34300.0;
const float umbral1 = 60.0;
const float umbral2 = 30.0;
const float umbral3 = 10.0;
 
// Define 3 objetos de motor paso a paso
// Motor No. 1 está configurado para operación de medio paso, motor No. 2 está configurado para operación de paso completo
 AccelStepper stepper1(FULLSTEP, motor1Pin1, motor1Pin3, motor1Pin2, motor1Pin4);
AccelStepper stepper2(FULLSTEP, motor2Pin1, motor2Pin3, motor2Pin2, motor2Pin4);
AccelStepper stepper3(FULLSTEP, motor3Pin1, motor3Pin3, motor3Pin2, motor3Pin4);
 
void setup() {

//  Serial.begin(9600);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);

  
  stepper1.setMaxSpeed(400.0);    // No. 1 velocidad máxima del motor 500 
  stepper1.setAcceleration(50.0);  // No. 1 aceleración del motor 50.0
 
  stepper2.setMaxSpeed(400.0);    // La velocidad máxima del motor No. 2 es 500 
  stepper2.setAcceleration(50.0);  // No. 2 aceleración del motor 50.0

  stepper3.setMaxSpeed(400.0);
  stepper3.setAcceleration(100.0);
}
 
void loop() {

  
// iniciarTrigger();
//float distancia = calcularDistancia();

  
 haciaAdelante();
  
  //stepper1.move(8192);
  //stepper2.move(8192);
  //stepper3.move(8192);
  
  stepper1.run();   // Motor No. 1 está funcionando
  stepper2.run();   // Motor No. 2 está funcionando
  stepper3.run();

 // Serial.print(distancia);
 // Serial.print("cm");
 // Serial.println();
}


//FUNCION INICIAR MEDIDOR
  
  void iniciarTrigger()
{
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(4);
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(TRIGGER, LOW);
}




// FUNCION CALCULAR DISTANCIA

float calcularDistancia()

{
  unsigned long tiempo = pulseIn(ECHO, HIGH);
  float distancia = tiempo * 0.000001 * sonido / 2.0;
  return distancia;
}

void velocidadMotor(float distancia)
{
  if (distancia > umbral1)
  {
        haciaAdelante();
  }
  else if (distancia < umbral2 && distancia > umbral3)
  {
    // motor a medias
     haciaAdelante();
  }
  else if (distancia <= umbral3)
  {
    // paramos motor
    haciaAdelante();
  }
}

void haciaAdelante()
{
  stepper1.move(8192);
  stepper2.move(8192);
 // stepper3.move(8192);
  //stepper1.run();   // Motor No. 1 está funcionando
  //stepper2.run();   // Motor No. 2 está funcionando
  //stepper3.run();
}
