#define E1 10  // Enable Pin for motor 1
#define I1 8     // Control pin 1 for motor 1
#define I2 9     // Control pin 2 for motor 1

void setup()
   {
        for (int i = 8 ; i<11 ; i++)                     // Inicializamos los pines
        pinMode( i, OUTPUT);
   }
void loop()
   {    digitalWrite(E1, HIGH);     // Activamos Motor1

   for(int f=0; f<255; f++){
analogWrite(E1, f);
delay(5);
        digitalWrite(I1, HIGH);     // Arrancamos
        digitalWrite(I2, LOW);
        delay(3000);
   }
        digitalWrite(E1, LOW);      // Paramos Motor 1
        delay(2000);
        digitalWrite(E1, HIGH);     // Activamos Motor1

        digitalWrite(I1, LOW);      // Arrancamos con cambio de direccion
        digitalWrite(I2, HIGH);
        delay(3000);
        digitalWrite(E1, LOW);      // Paramos Motor 1
        delay(2000);
  }


 
