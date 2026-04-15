#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const int ir = 2;
volatile int count = 0;
volatile bool prev_state = HIGH;


LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(ir, INPUT);
}

void loop() {
  bool cur_state = digitalRead(ir);

  if (!cur_state && prev_state) {
    prev_state = LOW;
  }
  if (cur_state && !prev_state) {
    count += 1;
    prev_state = HIGH;
    Serial.println(count);
    lcd.clear();
    lcd.print(count);
  }

}
