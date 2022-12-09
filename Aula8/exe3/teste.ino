// Função para o Interrupt
void teste() {
  Serial.println("Timer Interrupt");
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
}