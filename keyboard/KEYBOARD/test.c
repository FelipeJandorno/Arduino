/*
int main(){
  
  DDRD &= ~(1 << PD3);

  while(1){
    detect_button();
  }
}

byte detect_button(){
  byte code = 0;
  (PIND & (1<<PD3)) ? 1 : 0;
  return code;
}
*/