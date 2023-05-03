unsigned long read_time_out = millis();

void setup(){
  DDRD &= ~(1 << PD2);
  DDRD &= ~(1 << PD6);

  Serial.begin(9600);
  Serial.println("... conectando ...");
}

void loop(){
  if((millis() - read_time_out) < 100){
    detect_button() ? Serial.println("1") : Serial.println("0");
  } else if((millis() - read_time_out) > 100){
    //Serial.println("...");
  }

  if((millis() - read_time_out) > 1000){
    read_time_out = millis();
  }
}

uint8_t detect_button(){
  uint8_t state;
  (PIND & (1<<PD2)) ? state = 0 : state = 1;
  return state;
}