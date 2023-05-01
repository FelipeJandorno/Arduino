#define TRIGGER_HCSR 9
#define ECHO_HCSR 10

unsigned long timer = millis();
unsigned long call_back_timer = millis();
bool Pulse();

//=============================================================================//

void setup(){
  DDRB |= (1 << PB5); //Trigger = PB5
  DDRB &= ~(1 << PB4); //Echo = PB4

  Serial.begin(9600);
  Serial.println("... conectado ...");
}

void loop(){
    if(Serial.available() > 0){
      Serial.println(Pulse());
    }
}

//==============================================================================//

bool Pulse(){
  if((millis() - timer) < 1000){
      PORTB |= (1 << PORTB5);     
      return 1;
    } else if((millis() - timer) > 1000 && (millis() - timer) < 2000){
      PORTB &= (1 << PORTB5);
      return 0;
    } else if((millis() - timer) > 2000){
      timer = millis();
  }
}

float Read_distance(){
  while(PINB & (1 << PINB5)){
    call_back_timer = millis();
  } 

  unsigned float distance = (call_back_timer * 340)/2;
  return distance;  
}