//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __|
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/
//
// Name: Servomotor controlled by potentiometer
//
// Made by detemmerman thomas
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/5256580-the-unnamed-circuit

#include <Servo.h>

Servo myservo;
const int potIn = A5;

int potInValue;
int servOutValue;

void setup() {

  myservo.attach(1);
 pinMode(potIn, INPUT);
}

void loop() {
 	potInValue = analogRead(potIn);
  	servOutValue = map(potInValue, 0, 1023, 0, 180);
  	servOutValue = 180 - servOutValue; //reverse direction
    myservo.write(servOutValue);
delay(1);
}
