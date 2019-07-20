#define trigPin 7
#define echoPin 6
#define led 13
#define led2 12
#define led3 11
#define led4 10
#define led5 9
#define led6 8
#define buzzer 3

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C7, NOTE_C7, NOTE_C7, NOTE_C7, NOTE_D7, NOTE_C7, NOTE_D7, NOTE_E7
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 2
};



void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(buzzer, OUTPUT);
 
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 

  if (distance <= 30) {
    digitalWrite(led, HIGH);
}
  else {
    digitalWrite(led,LOW);
  }
  if (distance < 25) {
      digitalWrite(led2, HIGH);
}
  else {
      digitalWrite(led2, LOW);
  }
  if (distance < 20) {
      digitalWrite(led3, HIGH);
} 
  else {
    digitalWrite(led3, LOW);
  }
  if (distance < 15) {
    digitalWrite(led4, HIGH);
}
  else {
    digitalWrite(led4,LOW);
  }
  if (distance < 10) {
    digitalWrite(led5, HIGH);
}
  else {
    digitalWrite(led5,LOW);
  }
  if (distance < 5) {
    digitalWrite(led6, HIGH);
    
       //VICTORY MELODY
     // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(3, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(3);
  }
    
}
  else {
    digitalWrite(led6,LOW);
  }
 
  if (distance > 30 || distance <= 0){
    Serial.println("Out of range");
    noTone(buzzer);
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    tone(buzzer, sound);
   
  }
  delay(500);
}
