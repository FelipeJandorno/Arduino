/*
  Função: Armazenar valores na memória EEPROM do Arduino após inicializar o programa inserindo um valor aleatório no monitor Serial
  Data: 30/04/2023

  Variáveis Utilizadas e Funções =============================================================
  counter = Além de funcionar como um contador, será o valor que será armazenado na memória
  timer = Controla o tempo no qual adicionaremos +1 ao contador, bem como o tempo ocioso
  EEPROM.read(dx) - lê o valor armazenado no registrador dx
  EEPROM.write(dx, counter) - Armazena o valor da variável counter no registrador dx
  ============================================================================================
  Insrtução para o funcionamento do código

  01 - Conecte a placa arduino ao computador
  02 - Selecione a porta do Arduino
  03 - Compilar o código
  04 - Abrir o Monitor Serial
  05 - Inserir qualquer letra, número ou símbolo no monitor serial
  =============================================================================================  
*/

#include <EEPROM.h>

byte counter = 0;
unsigned long timer = millis();

void setup(){
  Serial.begin(9600);
  Serial.println("... Inicializando ...");
  
  counter = EEPROM.read(0);
  EEPROM.write(0, 0);
}

void loop(){
  //Verifica se existe alguma entrada no monitor serial
  if(Serial.available() > 0){
    EEPROM_H();
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
