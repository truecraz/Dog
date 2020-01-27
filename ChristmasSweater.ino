
#include <Servo.h> 

Servo myservo;

const int ledPin = 2; 
const int ledPin2 = 3;
const int ledPin3 = 4;
int incomingByte;  

void setup() {

  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  myservo.attach(9);
}

void loop() {
  if (Serial.available() > 0) {

    incomingByte = Serial.read();

    if (incomingByte == 'H') {
      digitalWrite(ledPin, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      myservo.write(150);

    }

    if (incomingByte == 'L') {
      digitalWrite(ledPin, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      myservo.write(20);
      
    }
  }
}
