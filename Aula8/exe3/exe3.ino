//
// Software Interrupt - Timers
//
#include <TimerOne.h>

unsigned long tempoanterior = 0;
const long intervalo = 1000;
const byte ledPin = 9;

void setup() {
  Timer1.initialize(2500); // Inicializa o Timer da interrupção (microsegundos)
  Timer1.setPeriod(25000); // Define o Tempo que irá ocoorer a próxima interrupção (microsegundos)
  Timer1.attachInterrupt(teste); // Atribui a função teste ao Interrupt
  Serial.begin(9600);
}

void loop() {
  if (millis() - tempoanterior >= intervalo) {
    tempoanterior = millis();
    Serial.println("Programa a executar");
  }
}