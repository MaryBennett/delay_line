// Aim: to make a 24kHz counter
// Only works with a decoder/counter and a second delay between each 72 (can use this to clear the tube)

// For 72bits: 40.49238
// For 36bits: 80.98477
# define timing 40.49238

#include <TimerOne.h>

// sends a pulse to reset the counter
void reset() {
  digitalWrite(8, HIGH);
  digitalWrite(8, LOW);
}

int tenCount = 0;

void setup() {
  // set counter to 24kHz
  Timer1.initialize(timing);
  pinMode(10, INPUT); // 10th
  pinMode(8, OUTPUT); //reset
  pinMode(11, INPUT); // 2nd
  Timer1.pwm(9, 512);

  pinMode(A0, INPUT); //microphone

  Serial.begin(9600);
  Serial.println("start");
  delay(1000);
  reset();
}

void loop() {
  int clk10 = digitalRead(10);
  int clk2 = digitalRead(11);
    
  if (clk10 == HIGH) {
    Serial.println("1");
    tenCount++;
  }

  if (tenCount == 7) {
    if (clk2 == HIGH) {  //72nd pulse
      tenCount = 0;
      Serial.println("72!!");
      delay(1000);
      reset();
    }
  }
  Serial.print("\t");
  Serial.println(analogRead(A0));
}
