#define pinCLK 3
#define pinDT 4

int contador = 0;
int estadoAtualCLK, estadoAnteriorCLK;

void setup(){
  pinMode(pinCLK, INPUT);
  pinMode(pinDT, INPUT);

  estadoAnteriorCLK = digitalRead(pinCLK);

  Serial.begin(9600);
  Serial.println("... inicializando ...");
}

void loop(){
  if(Serial.available() > 0){
    encoder();
  }
}

void encoder(){
  estadoAtualCLK = digitalRead(pinCLK);
  if(estadoAtualCLK != estadoAnteriorCLK){
    contador--;
  } else{
    contador++;
  }
  
  Serial.print("encoder: ");
  Serial.println(contador);

  estadoAnteriorCLK = estadoAtualCLK;
  delay(50);
}