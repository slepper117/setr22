//
// Botão de Pressão para Controlo de LED
//

//Exemplo: Acender LED ao pressionar botão
#define LED 13    //0 pin para o LED
#define BUTTON 7  //0 pin de input onde o Botão está ligado

int val = 0;  // val é usado para guardar o estado do pin de input
int i;
unsigned long time, timeinit = millis() / 1000;

void setup() {
  pinMode(LED, OUTPUT);    //Define o LED como um output
  pinMode(BUTTON, INPUT);  //Define o Botão como um input
  Serial.begin(9600);
}


void loop() {
  time = millis() / 1000 - timeinit;
  val = digitalRead(BUTTON);  //lê o valor de input e guarda-o

  // verifica se o Botão está HIGH (pressionado)
  if (val == HIGH) {
    Serial.print("Botão pressionado: ");
    Serial.print(time);
    Serial.print("s/n");

    for (i = 1; 1 <= 13; i++) {
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      delay(500);
    }
  } else {
    digitalWrite(LED, LOW);
  }
}