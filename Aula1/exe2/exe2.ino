//
// Sensor de Luz
//

// Projeto 2 Sensor de Luz
// pino de ligação do led
int ledPin = 6;
// pino de ligação do LDR
int ldrPin = 0;
// valor lido do LDR
int lightVal = 0;

void setup() {
  Serial.begin(9600);
  // definir os pinos como de saída
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Ler o valor do LDR
  lightVal = analogRead(ldrPin);

  Serial.print("\Leitura entrada analógica: ");
  Serial.print(lightVal);

  // Acende o led Vermelho
  digitalWrite(ledPin, HIGH);
  // Atraso com valor do lightVal
  delay(lightVal);
  // deslida o led vermelho
  digitalWrite(ledPin, LOW);
  // Atraso com valor do lightVal
  delay(lightVal);
}