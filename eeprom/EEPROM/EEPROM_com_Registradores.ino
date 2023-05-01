/*
  Função: Armazenar valores na memória EEPROM do Arduino após inicializar o programa inserindo um valor aleatório no monitor Serial
  Data: 30/04/2023

  Variáveis Utilizadas e Funções =============================================================
  counter = Além de funcionar como um contador, será o valor que será armazenado na memória
  timer = Controla o tempo no qual adicionaremos +1 ao contador, bem como o tempo ocioso
  EEPROM.read(dx) - lê o valor armazenado no registrador dx
  EEPROM.write(dx, counter) - Armazena o valor da variável counter no registrador dx
  ============================================================================================
*/
/*
#include <EEPROM.h>

byte counter = 0;
unsigned long timer = millis();

void EEPROM_write(unsigned int uiAddress, unsigned char ucData);
int EEPROM_read(unsigned int uiAdress);

void setup(){
  Serial.begin(9600);
  Serial.println("... Inicializando ...");
  
  counter = EEPROM_read(EEAR0);
  EEPROM_write(EEAR0, 0);
}

void loop(){
  if(Serial.available() > 0){
    EEPROM_R();
  }
}

void EEPROM_H(){
  if(Serial.available() > 0){
        if((millis() - timer) < 100){
          counter++;
          EEPROM.write(0, counter);
          Serial.print("EEPROM: ");
          Serial.println(EEPROM.read(0));
        } else if((millis() - timer) > 2000){
          timer = millis();
        }
      }
}
*/