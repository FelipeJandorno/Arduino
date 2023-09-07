/* 
  Referências:
  [01] RoboCore. Primeiros Passos com o DS18B20. Disponível em <https://www.robocore.net/tutoriais/primeiros-passos-ds18b20-arduino>
  [02] Arduino. DallasTemperature Documentation. Disponível em <https://www.arduino.cc/reference/en/libraries/dallastemperature/>
*/

#include <OneWire.h>
#include <DallasTemperature.h>

// ---------------------------- Read temp ----------------------------//

#define TEMP_ONEWIRE_SENSOR_PIN 12

OneWire oneWire(TEMP_ONEWIRE_SENSOR_PIN);
DallasTemperature sensor(&oneWire);
DeviceAddress deviceAddress;

void get_temp(){
  sensor.requestTemperatures();
  float tempC = sensor.getTempCByIndex(0);

  if(tempC != DEVICE_DISCONNECTED_C){
    Serial.print("INFO: Temperatura (C°)- ");
    Serial.println(tempC);
  } else{
    Serial.println("ERROR: Sensor não encontrado");
  }
}

// ------------------------- Setup and Loop -------------------------//
void setup(){
  // Serial configuration
  Serial.begin(9600);

  // Starting temp sensors
  sensor.begin();
}

void loop(){
  get_temp();
  delay(1000);
}
