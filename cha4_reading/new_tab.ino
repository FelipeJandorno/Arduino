/*#include <Wire.h>

// Endereço I2C do ADS7828
#define ADS7828_ADDRESS 0x48

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  int sensorValue = readADS7828(0);  // Ler o canal 0 (ajuste conforme necessário)
  float concentration = convertToConcentration(sensorValue);  // Converta para concentração de CH4
  Serial.print("Valor lido: ");
  Serial.println(sensorValue);
  Serial.print("Concentracao de CH4: ");
  Serial.println(concentration);
  delay(1000);  // Aguardar um segundo antes da próxima leitura
}

int readADS7828(byte channel) {
  Wire.beginTransmission(ADS7828_ADDRESS);
  Wire.write(0x80 | (channel & 0x07) << 4);
  Wire.endTransmission();

  Wire.requestFrom(ADS7828_ADDRESS, 2);
  while (Wire.available() < 2);

  byte msb = Wire.read();
  byte lsb = Wire.read();

  int value = (msb << 8) | lsb;
  return value;
}

float convertToConcentration(int sensorValue) {
  // Adicione aqui a lógica de conversão do valor lido para concentração de CH4
  // Isso dependerá das características e calibração do seu sensor
  // Um exemplo simples poderia ser uma fórmula linear ou uma tabela de calibração
  // Concentração = a * sensorValue + b
  float concentration = a * sensorValue + b;
  return concentration;
}
*/