unsigned long timer = millis();

void setup(){
  Serial.begin(9600);
  Serial.println("... conectando ...");

  DDRB &= ~(1 << DDB4);
}

void loop(){
  if(Serial.available() > 0){
    read_ir();
  }
}

void read_ir(){
  unsigned long timer = millis();

  if(PINB & (1<<PINB4)){
    Serial.println("ON");
  } else{
    Serial.println("OFF");
    
    if((millis() - timer) < 1000){

    } else if((millis() - timer) > 2000){
      
    }
  }
}