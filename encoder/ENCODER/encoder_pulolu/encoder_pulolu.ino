#define ENCA 2
#define ENCB 3
#define deltaPulso 1000

unsigned long verificaPulso, dt, ultimaVerificacao;
volatile unsigned long pulso;
float velocidade;

void contPulso(){
  pulso++;
}



void setup(){
  Serial.begin(9600);
  pinMode(ENCA, INPUT);
  pulso = 0;
  verificaPulso = millis();
  attachInterrupt(0, contPulso, FALLING);
}

void loop(){
  if (millis() >= verificaPulso){
    dt = millis() - ultimaVerificacao;
    noInterrupts();
    // calcula velocidade (k = 330/2.78 = 118.70)
    velocidade = 118.7 * pulso / dt; // pulso/ms
    pulso = 0;
    interrupts();
    ultimaVerificacao = millis();
    verificaPulso = ultimaVerificacao + deltaPulso;
    Serial.println(velocidade, " RPM");
  }
}