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

// Realiza o armazenamento do valor do contadore a partir dos registradores do arduino
void EEPROM_R(){
  if((millis() - timer) < 0.001){
    counter++;
    EEPROM_write(EEAR0, counter);
    Serial.print(counter);
    Serial.print(" EEPROM: ");
    Serial.println(EEPROM_read(EEAR0));
  } else if((millis() - timer) > 2000){
    timer = millis();
  }
}

void EEPROM_write(unsigned int uiAddress, unsigned char ucData){
  while(EECR & (1 << EEPE)){
    EEAR = uiAddress;
    EEDR = ucData;

    EECR |= (1<<EEMPE);
    EECR |= (1<<EEPE);
  }
}

int EEPROM_read(unsigned int uiAdress){
  while(EECR & (1 << EEPE)){
    EEAR |= uiAdress;
    EECR |= (1<<EERE);
  }
  
  return EEDR;
}