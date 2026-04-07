const int ledPin = 2;
const int buttonPin = 3;

unsigned long ledOnTime = 0;
unsigned long randomDelayTime = 0;
unsigned long startTime = 0;

bool ledState = false;
bool waitingForPress = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);

  startNewRound();
}

void loop() {
  unsigned long currentTime = millis();

  if (!ledState && (currentTime - startTime >= randomDelayTime)) {
    digitalWrite(ledPin, HIGH);
    ledOnTime = currentTime;
    ledState = true;
    waitingForPress = true;
  }

  if (waitingForPress && digitalRead(buttonPin) == LOW) {
    unsigned long reactionTime = currentTime - ledOnTime;

    Serial.print("Reaction Time: ");
    Serial.print(reactionTime);
    Serial.println(" ms");

    delay(500); 
    startNewRound();
  }
}

void startNewRound() {
  digitalWrite(ledPin, LOW);

  ledState = false;
  waitingForPress = false;

  startTime = millis();
  randomDelayTime = random(2000, 5000);
}
