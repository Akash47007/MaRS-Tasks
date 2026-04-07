const int led1 = 2; // (500ms)
const int led2 = 3; // (1000ms)
const int led3 = 4; // (1500ms)

// Stores the previous time where there has been an update to the leds
unsigned long p1 = 0;
unsigned long p2 = 0;
unsigned long p3 = 0;

// Stores the current stare of the respective leds
int s1 = LOW;
int s2 = LOW;
int s3 = LOW;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  unsigned long curr = millis();

  // LED 1: 500ms
  if ((curr - p1 >= 500) || (s1 == HIGH && curr - p1 >= 20)) {
    if (s1 != HIGH) p1 = curr;
    s1 = (s1 == LOW) ? HIGH : LOW;
    digitalWrite(led1, s1);
  }

  // LED 2: 1000ms
  if ((curr - p2 >= 1000) || (s2 == HIGH && curr - p2 >= 20)) {
    if (s2 != HIGH) p2 = curr;
    s2 = (s2 == LOW) ? HIGH : LOW;
    digitalWrite(led2, s2);
  }

  // LED 3: 1500ms
  if ((curr - p3 >= 1500) || (s3 == HIGH && curr - p3 >= 20)) {
    if (s3 != HIGH) p3 = curr;
    s3 = (s3 == LOW) ? HIGH : LOW;
    digitalWrite(led3, s3);
  }
}
