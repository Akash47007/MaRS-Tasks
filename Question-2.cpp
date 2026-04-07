const int potPin = A0;

const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

const int ledPin = 3;
unsigned long prev = 0;
int state = LOW;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  int potValue = analogRead(potPin);
  unsigned long curr = millis();

  int r = 0, g = 0, b = 0;

  // Color control logic
  if (potValue < 341) {
    r = map(potValue, 0, 340, 255, 0);
    g = map(potValue, 0, 340, 0, 255);
    b = 0;
  }
  else if (potValue < 682) {
    r = 0;
    g = map(potValue, 341, 681, 255, 0);
    b = map(potValue, 341, 681, 0, 255);
  }
  else {
    r = map(potValue, 682, 1023, 0, 255);
    g = 0;
    b = map(potValue, 682, 1023, 255, 0);
  }

  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);

  // Blink control
  int delayTime = map(potValue, 0, 1023, 1000, 100);
  
  if (curr - prev >= delayTime) {
    prev = curr;
    state = (state == LOW)? HIGH : LOW;
  	digitalWrite(ledPin, state);
  }
}
