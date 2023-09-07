#include <SoftwareSerial.h>


byte raw_data;
SoftwareSerial arduinoUno(9, 8); // RX, TX 


void setup(){
  Serial.begin(4800);
  arduinoUno.begin(9600);
}


void loop(){
  if(Serial.available()){
    if(arduinoUno.available() > 0){
      raw_data = arduinoUno.read();
      Serial.write(raw_data);
    }
  }


  delay(100);
}
