// Definimos los pines donde tenemos conectadas los motores y los sensores

#define TRIGGER 2 // Trigger Sensor Distancia
#define ECHO 3    // Echo Sensor Distancia
#define IN1  4 //Motor1 Pin1
#define IN2  5 //Motor1 Pin2
#define IN3  6 //Motor1 Pin3
#define IN4  7 //Motor1 Pin4
#define IN5  8 //Motor2 Pin1
#define IN6  9 //Motor2 Pin2
#define IN7  10 //Motor2 Pin3
#define IN8  11 //Motor2 Pin4
#define DIR1 14 //Motor Direccion Pin1
#define DIR2 15 //Motor Direccion Pin2
#define DIR3 16 //Motor Direccion Pin3
#define DIR4 17 //Motor Direccion Pin4

// Definimos Constante de la velocidad del sonido

const float sonido = 34300.0;

// Definimos los umbrales de distancia para la toma de decisiones

const float umbral1 = 100.0;
const float umbral2 = 99.0;
const float umbral3 = 50.0;


 
// Secuencia de pasos de los motores(par máximo).
int paso [4][4] =
{
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
};
 
void setup()
{
  // Todos los pines en modo salida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  pinMode(IN14, OUTPUT);
  pinMode(IN15, OUTPUT);
  pinMode(IN16, OUTPUT);
  pinMode(IN17, OUTPUT);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);

 
}
 
 
 
void loop()
{ 
  
  iniciarTrigger();
  float distancia = calcularDistancia();
  todoMotor();
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

  
  
}
  
   
void todoMotor();

  { 
    for (int i = 0; i < 4; i++)
    {
      digitalWrite(IN1, paso[i][0]);
      digitalWrite(IN5, paso[i][0]);
      digitalWrite(IN2, paso[i][1]);
      digitalWrite(IN6, paso[i][1]);
      digitalWrite(IN3, paso[i][2]);
      digitalWrite(IN7, paso[i][2]);
      digitalWrite(IN4, paso[i][3]);
      digitalWrite(IN8, paso[i][3]);
      delay(10);
    }
  }

void marchaAtras()

  { 
    for (int i = 4; i > 0; i--)
    {
      digitalWrite(IN1, paso[i][0]);
      digitalWrite(IN5, paso[i][0]);
      digitalWrite(IN2, paso[i][1]);
      digitalWrite(IN6, paso[i][1]);
      digitalWrite(IN3, paso[i][2]);
      digitalWrite(IN7, paso[i][2]);
      digitalWrite(IN4, paso[i][3]);
      digitalWrite(IN8, paso[i][3]);
      delay(10);
    }
  }
