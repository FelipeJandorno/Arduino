#include <Wire.h>

// Endereço I2C do ADS7828
#define ADS7828_CH1 0b10010100
#define ADS7828_CH3 0b11010100
#define ADS7828_ADDRESS 0b10010000
#define ADD_SDA 8
#define ADD_SCL 9

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  Serial.println(readADS7828(ADS7828_CH1));
  delay(100);
}

int readADS7828(byte channel){
  Wire.beginTransmission(ADS7828_ADDRESS);
  Wire.write(channel);
  Wire.endTransmission();

  Wire.requestFrom(ADS7828_ADDRESS, 2);
  while(Wire.available() < 2);

  byte msb = Wire.read();
  byte lsb = Wire.read();

  int value = (msb << 8) | lsb;
  return value;
}

void readCH4Sensor(){
  //int ch4_value = readADS7828(1);
  //Serial.print("ch4: ");
  //Serial.println(ch4_value);
}