int BUT1 = D0;
int BUT2 = D1;
int BUT3 = D2;
int BUT4 = D3;

int LED1 = D4;
int LED2 = D5;
int LED3 = D6;

int score = 0;
int currentLED = 0;

long gameStart = 0;
bool gameRunning = false;

void setup() {
  pinMode(BUT1, INPUT_PULLUP);
  pinMode(BUT2, INPUT_PULLUP);
  pinMode(BUT3, INPUT_PULLUP);
  pinMode(BUT4, INPUT_PULLUP);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  digitalWrite(LED1, HIGH);
  delay(300);
  digitalWrite(LED1, LOW);

  digitalWrite(LED2, HIGH);
  delay(300);
  digitalWrite(LED2, LOW);

  digitalWrite(LED3, HIGH);
  delay(300);
  digitalWrite(LED3, LOW);

  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
}

void loop() {

  if (!gameRunning) {
    if (digitalRead(BUT4) == LOW) {
      delay(200);
      startGame();
    }
    return;
  }

  if (millis() - gameStart >= 30000) {
    endGame();
    return;
  }

  playRound();
}

void startGame() {
  score = 0;
  gameRunning = true;
  gameStart = millis();

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
}

void playRound() {

  currentLED = random(1, 4);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);

  if (currentLED == 1) digitalWrite(LED1, HIGH);
  if (currentLED == 2) digitalWrite(LED2, HIGH);
  if (currentLED == 3) digitalWrite(LED3, HIGH);

  long start = millis();
  bool scored = false;

  while (millis() - start < 1000) {

    if (!scored) {

      if (currentLED == 1 && digitalRead(BUT1) == LOW) {
        score++;
        scored = true;
      }

      if (currentLED == 2 && digitalRead(BUT2) == LOW) {
        score++;
        scored = true;
      }

      if (currentLED == 3 && digitalRead(BUT3) == LOW) {
        score++;
        scored = true;
      }
    }
  }

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);

  delay(200);
}

void endGame() {

  gameRunning = false;

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);

  if (score == 20) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
  }

  else if (score > 10) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
  }

  else {
    digitalWrite(LED1, HIGH);
  }

  delay(10000);

  for (int i = 0; i < 2; i++) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    delay(300);

    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    delay(300);
  }

  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
}