#include <avr/power.h>
#include "util/delay.h"

// Define the pins for the ultrasonic sensor
const int trigPin = 9;   // Trig pin of ultrasonic sensor connected to Arduino pin 9
const int echoPin = 10;  // Echo pin of ultrasonic sensor connected to Arduino pin 10


#define rear_motors_ena 5
#define rear_motors_in1 4
#define rear_motors_in2 3

#define front_motor_enb 6
#define front_motor_in3 2
#define front_motor_in4 7


void moveStraightForward(int speed) {

  digitalWrite(rear_motors_in1, HIGH);
  digitalWrite(rear_motors_in2, LOW);
  analogWrite(rear_motors_ena, speed);
}

void moveStraightBackward(int speed) {

  digitalWrite(rear_motors_in1, LOW);
  digitalWrite(rear_motors_in2, HIGH);
  analogWrite(rear_motors_ena, speed);
}

void turnRight(int speed) {

  digitalWrite(front_motor_in3, HIGH);
  digitalWrite(front_motor_in4, LOW);
  analogWrite(front_motor_enb, speed);
}

void turnLeft(int speed) {
  digitalWrite(front_motor_in3, LOW);
  digitalWrite(front_motor_in4, HIGH);
  analogWrite(front_motor_enb, speed);
}

void stopFrontMotor(void) {
  digitalWrite(front_motor_in3, LOW);
  digitalWrite(front_motor_in4, LOW);
  analogWrite(front_motor_enb, LOW);
}

void stopRearMotors(void) {
  digitalWrite(rear_motors_in1, LOW);
  digitalWrite(rear_motors_in2, LOW);
  analogWrite(rear_motors_ena, LOW);
}

void centerTheWheel(void) {
  turnRight(255);
  delay(63);
  turnLeft(255);
  delay(25);
  stopFrontMotor();
}

void setup() {
  clock_prescale_set(clock_div_1);
  Serial.begin(9600);        // Initialize serial communication at 9600 baud rate
  pinMode(trigPin, OUTPUT);  // Set trigPin as OUTPUT
  pinMode(echoPin, INPUT);   // Set echoPin as INPUT

  pinMode(rear_motors_ena, OUTPUT);
  pinMode(rear_motors_in1, OUTPUT);
  pinMode(rear_motors_in2, OUTPUT);

  pinMode(front_motor_enb, OUTPUT);
  pinMode(front_motor_in3, OUTPUT);
  pinMode(front_motor_in4, OUTPUT);

  digitalWrite(rear_motors_ena, LOW);
  digitalWrite(front_motor_enb, LOW);
}

void loop() {
 //moveStraightBackward(100);

  int duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");


  // Check if an object is detected
  if (distance <= 20) {
    //stopRearMotors();

  } else {
   // moveStraightBackward(100);
  }

  // Delay before the next measurement
  delay(300);
}
