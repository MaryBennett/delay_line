// Aim: to wake the arduino up every 80us to do stuff
// Using the timerOne header file which deals with all the registers
/*********************************************************************/
// 2017-08-03 <Mary Bennett>
//   Wrote program for decade counter (used 72bit first)
// 2017-08-04 <Mary Bennett>
//  Removed loop()
//  Added isr() -> called every 12kHz from set up
//  Added initBits () to set the tesing array; first
// 2017-08-07 <Mary Bennett>
//  Added initialise routine to fix timing error
/*********************************************************************/

#include <TimerOne.h>

// Number of bits
const int NUMBITS = 36;

// Work out number of usecs per bit, on the basis that the speed of sound
// is 343 m/s and the tube is 1 m long
// For 36bits: 80.98477, wait a second then send the other half
const long int TIMING = 1000000L / 343 / NUMBITS /2;

// Array for 1 word

boolean first[NUMBITS];
boolean second[NUMBITS];

// Microphone is set to digital pin 4

const uint8_t MICROPHONE_PIN = 4;

// Speaker is on digital pin 2

const uint8_t SPEAKER_PIN = 2;

// The next bit to process

int nextBit;

// Current output state

uint8_t currPulse;


/**********************************************************************/

// Initialises the array for speaker input.

// This is for testing only.  We start with alternating bits (010101010...)
void initBits() {
  
  for (int i = 0; i < NUMBITS; i++)
  {
    first[i] = (i % 2);
  }
}


// ISW wakes up at 12kHz. Get everything done in 80us!
// Read the microphone
// Store in array
// Send next pulse (done)
void isr () {
  
  // Output: if a 1, change pulse
  if (first[nextBit] == 1) 
  {
    if (currPulse == LOW) currPulse = HIGH;
    else currPulse = LOW;
    //currPulse = (LOW == currPulse) ? HIGH : LOW;
  }
  digitalWrite (SPEAKER_PIN, currPulse);

  // Input (save to first[nextBit)
/*  if (nextBit == 0)
  {
    first[NUMBITS - 1] = digitalRead(MICROPHONE_PIN);
  }
  else first[nextBit--] = digitalRead(MICROPHONE_PIN);
*/ 
  // increment next bit
  if (nextBit == (NUMBITS - 1))
  {
    nextBit = 0;
  }
  else nextBit++;
}

void setup() {
  
  // pin setups
  
  pinMode(MICROPHONE_PIN, INPUT); // microphone
  pinMode(SPEAKER_PIN, OUTPUT);  // speaker

  // Initialize the bits to send
  
  initBits ();

  // Initialize variables
  nextBit = 0;
  currPulse = LOW;
  
  // Initialize timer
  
  Timer1.initialize(TIMING);
  
  // set counter to 12kHz
  
  Timer1.attachInterrupt (isr, TIMING);  // wakes the arduino up every timing, uses interupts
}

// Don't need
void loop(){}
