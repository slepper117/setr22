//
// Botão de Pressão para Controlo de LED
//

//Exemplo: Acender LED ao pressionar botão
#define LED 13    //0 pin para o LED
#define BUTTON 7  //0 pin de input onde o Botão está ligado

int val = 0;  // val é usado para guardar o estado do pin de input

void setup() {
  pinMode(LED, OUTPUT);    //Define o LED como um output
  pinMode(BUTTON, INPUT);  //Define o Botão como um input
}


void loop() {
  val = digitalRead(BUTTON);  //lê o valor de input e guarda-o

  // verifica se o Botão está HIGH (pressionado)
  if (val == HIGH) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}