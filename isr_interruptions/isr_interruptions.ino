// Pin Change Interrupt Timing
// PCICR - Pin Change Interrupt Control Register (1 can trigger | 0 cant trigger)

/* PCIE0 bit control PCINT0 to PCINT7
   PCIE1 bit control PCINT8 to PCINT14
   PCIE2 bit control PCINT16 to PCINT23
*/

ISR(PCINT2_vect){
  
}

void setup(){
  PCICR  |= 0b00000100; 
  PCMSK2 |= 0b00100000;
}

void loop(){
  
}