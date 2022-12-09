//
// Luzes de Trânsito (Semáforos)
//

// Projeto 1 Semáforos
int ledDelay = 10000;  // atraso entre mudança de led
int redPin = 10;
int yellowPin = 9;
int greenPin = 8;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // acender o led vermelho
  digitalWrite(redPin, HIGH);
  delay(ledDelay);  // espera 10 segundos

  digitalWrite(yellowPin, HIGH);  // Acende o led amarelo
  delay(2000);                    // espera 2 segundos

  digitalWrite(greenPin, HIGH);  // acende o led verde
  digitalWrite(redPin, LOW);     // apaga o led vermelho
  digitalWrite(yellowPin, LOW);  // apaga o led amarelo
  delay(ledDelay);               // espera 10 segundos

  digitalWrite(yellowPin, HIGH);  // acende o led amarelo
  digitalWrite(greenPin, LOW);    // apaga o led verde
  delay(2000);                    // espera 2 segundos

  digitalWrite(yellowPin, LOW);  // apaga o led amarelo
}