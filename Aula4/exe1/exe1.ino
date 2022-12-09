//
// Efeito perseguição com 10 LEDs controlo via potenciómetro
//

//Projeto efeito perseguição LED
//Criação de array para os pinos dos LEDS
byte ledPin[] = { 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
int ledDelay;  //delay entre mudança
int direction = 1;
int currentLED = 0;
unsigned long changeTime;
int potPin = 2;  // pino do potenciómetro

void setup() {
  // Definir todos os pinos como OUTPUT
  for (int x = 0; x < 10; x++) {
    pinMode(ledPin[x], OUTPUT);
    changeTime = millis();
  }
}

void loop() {
  // lê o valor do potenciómetro
  ledDelay = analogRead(potPin);
  // se passaram ledDelay ms desde a última mudança
  if ((millis() - changeTime) > ledDelay) {
    changeLED();
    changeTime = millis();
  }
}

void changeLED() {
  //desliga todos os LEDs
  for (int x = 0; x < 10; x++) {
    digitalWrite(ledPin[x], LOW);
  }
  //acende o LED atual
  digitalWrite(ledPin[currentLED], HIGH);
  // incrementa pelo valor da direção
  currentLED += direction;
  //mudar de direção caso chegue ao fim
  if (currentLED == 9) direction = -1;
  if (currentLED == 0) direction = 1;
}