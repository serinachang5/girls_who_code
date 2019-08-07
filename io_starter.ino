#include <Servo.h>

int CLOCKWISE = 1300;
int COUNTERCLOCKWISE = 1700;
int STILL = 1500;

/* 
 *  Full octave of notes.
 *  s stands for sharp, e.g. As4 is A-sharp.
 *  b stands for flat, e.g. Db5 is D-flat.
 */
int NOTE_A4 = 440;
int NOTE_As4 = 466;
int NOTE_Bb4 = NOTE_As4;
int NOTE_B4 = 494;
int NOTE_C5 = 523;
int NOTE_Cs5 = 554;
int NOTE_Db5 = NOTE_Cs5;
int NOTE_D5 = 587;
int NOTE_Ds5 = 622;
int NOTE_Eb5 = NOTE_Ds5;
int NOTE_E5 = 659;
int NOTE_F5 = 698;
int NOTE_Fs5 = 740;
int NOTE_Gb5 = NOTE_Fs5;
int NOTE_G5 = 784;
int NOTE_Gs5 = 830;
int NOTE_Ab5 = NOTE_Gs5;

Servo leftWheel;    // signal controlling left wheel
Servo rightWheel;   // signal controlling right wheel
int piezoPin;       // output pin for piezo speaker
int leftWhiskerPin;     // pin receiving signals from left whisker
int rightWhiskerPin;    // pin receiving signals from right whisker
byte leftWhiskerSignal; // voltage received in left whisker pin
byte rightWhiskerSignal;// voltage received in right whisker pin

void setup() {
  // Set up pins
  leftWheel.attach(12);
  rightWheel.attach(13);
  piezoPin = 13;
  leftWhiskerPin = 6;
  rightWhiskerPin = 10;

  // Set-up functions
  stopMoving();
  pinMode(piezoPin, OUTPUT);
  pinMode(leftWhiskerPin, INPUT);
  pinMode(rightWhiskerPin, INPUT);
  
  Serial.begin(9600);
}

void moveForward() {
  leftWheel.writeMicroseconds(CLOCKWISE);
  rightWheel.writeMicroseconds(COUNTERCLOCKWISE);
}

void moveBackward() {
  leftWheel.writeMicroseconds(COUNTERCLOCKWISE);
  rightWheel.writeMicroseconds(CLOCKWISE);
}

void turnLeft() {
  leftWheel.writeMicroseconds(STILL);
  rightWheel.writeMicroseconds(COUNTERCLOCKWISE);
}

void turnRight() {
  leftWheel.writeMicroseconds(CLOCKWISE);
  rightWheel.writeMicroseconds(STILL);
}

void stopMoving() {
  leftWheel.writeMicroseconds(STILL);
  rightWheel.writeMicroseconds(STILL);
}

/*
 * Plays the first line of Twinkle, Twinkle, Little Star 
 * on Piezo speaker.
 */
void playTwinkle() {
  tone(piezoPin, NOTE_A4, 200);
  delay(500);
  tone(piezoPin, NOTE_A4, 200);
  delay(500);
  tone(piezoPin, NOTE_E5, 200);
  delay(500);
  tone(piezoPin, NOTE_E5, 200);
  delay(500);
  tone(piezoPin, NOTE_Fs5, 200);
  delay(500);
  tone(piezoPin, NOTE_Fs5, 200);
  delay(500);
  tone(piezoPin, NOTE_E5, 400);
  delay(1000);
  tone(piezoPin, NOTE_D5, 200);
  delay(500);
  tone(piezoPin, NOTE_D5, 200);
  delay(500);
  tone(piezoPin, NOTE_Cs5, 200);
  delay(500);
  tone(piezoPin, NOTE_Cs5, 200);
  delay(500);
  tone(piezoPin, NOTE_B4, 200);
  delay(500);
  tone(piezoPin, NOTE_B4, 200);
  delay(500);
  tone(piezoPin, NOTE_A4, 400);
}

/*
 * Updates the global variables leftWhiskerSignal and
 * rightWhiskerSignal with the latest digital reads.
 * Prints the updated values to the console.
 */
boolean logWhiskerSignals() {
  leftWhiskerSignal = digitalRead(leftWhiskerPin);
  rightWhiskerSignal = digitalRead(rightWhiskerPin);
  Serial.print("Left: ");
  Serial.println(leftWhiskerSignal); 
  Serial.print("Right: ");
  Serial.println(rightWhiskerSignal);
}

void loop() {
  playTwinkle();
  delay(2000);

//  Uncomment to test whiskers
//  logWhiskerSignals();
//  delay(100);
}
