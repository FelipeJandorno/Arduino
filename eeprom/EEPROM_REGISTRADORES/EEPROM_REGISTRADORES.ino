/*
  Data: 01/05/2023
  Função: Realizar a leitura e o armazenamento de dados na EEPROM do arduino 
  utilizando apenas registradores
*/
//Declaração do contador e do timer
byte counter = 0;
unsigned long timer = millis();

//Funções de leitura e escrita na EEPROM
void EEPROM_write(unsigned int register_addr, unsigned char byte_data);
int EEPROM_read(unsigned int register_addr);

void setup(){
  Serial.begin(9600);
  Serial.println("... Inicializando ...");
  
  //Atribui o valor armazenado na EEPROM ao contador antes de iniciar o programa
  counter = EEPROM_read(EEAR0);
  
  //Passa o valor zero para o registrador EEAR0
  EEPROM_write(EEAR0, 0);  
}

void loop(){
  
  //Verifica se algum valor foi adicionado à entrada do monitor serial
  if(Serial.available() > 0){
    EEPROM_R();
  }  
}

/* Incrementa o contador após 1990 ms, adiciona o valor do contador
à EEPROM e lê o valor armazenado na EEPROM*/
void EEPROM_R(){
  if((millis() - timer) < 10){
    counter++;
    EEPROM_write(EEAR0, counter);
    Serial.print(" EEPROM: ");
    Serial.println(EEPROM_read(EEAR0));
  } else if((millis() - timer) > 2000){
    timer = millis(); //Reinicia o contador
  }
}

void EEPROM_write(unsigned int register_addr, unsigned char byte_data){
  while(EECR & (1 << EEPE));
    EEAR = register_addr;
    EEDR = byte_data;
    EECR |= (1<<EEMPE);
    EECR |= (1<<EEPE);
}

int EEPROM_read(unsigned int register_addr){
  
  EEAR = register_addr;
  EECR |= (1<<EERE);
  EECR |= (1<<EEPE);
  
  while(EECR & (1 << EEPE));
  return EEDR;
}