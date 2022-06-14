#define pinSensor 2

int contador = 0;
int estadoActual = 0;
int estadoAnterior = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //9600 es una velocidad en boudios
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(pinSensor,INPUT); //INPUT, INPUT_PULLUP, OUTPUT
  //Por default los pines digitales son de entrada
}

void loop() {
  // put your main code here, to run repeatedly:
  int estadoActual = digitalRead(pinSensor);
  if (estadoActual != estadoAnterior){
    if (estadoActual == LOW){
      contador++;
      Serial.print("Objeto detectado. ");
      Serial.print("Conteo de objetos en: ");
      Serial.println(contador);
      digitalWrite(LED_BUILTIN,LOW);
    }else{
       Serial.println("Objeto no detectado");
       digitalWrite(LED_BUILTIN,HIGH);          
    }
    delay(100);
  }
  estadoAnterior = estadoActual;
}
