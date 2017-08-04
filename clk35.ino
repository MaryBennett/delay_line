// Aim: to wake the arduino up every 80us to do stuff
// Using the timerOne header file which deals with all the registers
/*********************************************************************/
// 2017-08-03 <Mary Bennett>
//   Wrote program for decade counter (used 72bit first)
// 2017-08-04 <Mary Bennett>
//  Removed loop()
//  Added isr() -> called every 12kHz from set up
/*********************************************************************/

#include <TimerOne.h>

// For 36bits: 80.98477, wait a second then send the other half
# define timing 80.98477
// array for first word
boolean FIRST[37];
// array for second word
boolean SECOND[37];

int micPin = A0;
int spePin = 2;

int j = 0;
boolean currPulse = 0;

/**********************************************************************/

// Initialises the first/ second arrays (for testing only)
void initi() {
  int i = 0;
  
  for (i = 0; i < 36; i++)
  {
    FIRST[i] = (boolean)(i % 2);
    SECOND[i] = (boolean)(i % 2);
  }
}


// ISW wakes up at 12kHz. Get everything done in 80us!
// Read the microphone
// Store in array
// Send next pulse (done)
void isr () {
  Timer1.pwm(9, 512);  // duty cycle = 512/1024, output is pin 9
  
  boolean *ptr[37];
  
  // Finds which array to use
  if(j < 36) *ptr = FIRST;
  else *ptr = SECOND;

  // Input
  
  // OutPut
  // if a 1, change pulse
  if(*ptr[j%37] == 1) {
    currPulse = (boolean)((currPulse + 1) % 2);
  }
  digitalWrite(spePin, *ptr[j%37]);
  digitalWrite(3, *ptr[j%37]);

  // Next j
  j++;
  j = j % 72;
}

void setup() {
  // pin setups
  pinMode(micPin, INPUT); // microphone
  pinMode(spePin, OUTPUT);  // speaker
  pinMode(3, OUTPUT); //test

  Serial.begin(9600);
  initi();
  
  // set counter to 12kHz
  Timer1.attachInterrupt (isr, timing);  // wakes the arduino up every timing, uses interupts
  Timer1.pwm(9, 512);  // duty cycle = 512/1024, output is pin 9

}

void loop(){}
