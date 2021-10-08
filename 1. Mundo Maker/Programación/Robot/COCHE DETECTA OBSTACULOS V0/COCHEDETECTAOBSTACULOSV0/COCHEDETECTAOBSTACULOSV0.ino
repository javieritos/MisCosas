#define E1 10  // Enable Pin for motor 1
#define I1 8     // Control pin 1 for motor 1
#define I2 9     // Control pin 2 for motor 1
#define TRIGGER 7 //Pin de sensor Trigger
#define ECHO 6

//Constantes

const float sonido = 34300.0;
const float umbral1 = 60.0;
const float umbral2 = 59.0;
const float umbral3 = 30.0;


void setup()
   {
    Serial.begin(9600);
        for (int i = 8 ; i<11 ; i++)                     // Inicializamos los pines
        pinMode( i, OUTPUT);
        pinMode(TRIGGER, OUTPUT);
        pinMode(ECHO, INPUT);
   }



void loop()
   {  
  iniciarTrigger();
  float distancia = calcularDistancia();
  
      //  pararMotor();
      //  delay (3000);  


        
      //  medioMotor();
      //  delay (3000);
        todoMotor();
     //  delay (3000);  

     if (distancia < umbral1)
  {
    // Lanzamos alertas
   velocidadMotor(distancia);
  }
  Serial.print(distancia);
  Serial.print("cm");
  Serial.println();
  delay(100);
  }

 
  //FUNCION PARAR MOTOR
  
  void pararMotor()
    {
      digitalWrite(I1, LOW);
      digitalWrite(I2, LOW);
    }

  //FUNCION MOTOR A MEDIA MARCHA
  void medioMotor()
  {
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    analogWrite(E1, 127);
  }

  //FUNCION MOTOR A TOPE

 void todoMotor()
  {
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    analogWrite(E1, 255);
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

// FUNCION DIRECCION MOTOR

void velocidadMotor(float distancia)
{
  if (distancia < umbral1 && distancia >= umbral2)
  {
    // TODO MOTOR
    todoMotor();
  }
  else if (distancia < umbral2 && distancia > umbral3)
  {
    // motor a medias
    medioMotor();
  }
  else if (distancia <= umbral3)
  {
    // paramos motor
    pararMotor();
  }
}

 
