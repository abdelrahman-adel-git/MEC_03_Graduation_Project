#include <avr/power.h>
#include <avr/io.h>

#define rear_motors_ena 11
#define rear_motors_in1 4
#define rear_motors_in2 3

#define front_motor_enb 6
#define front_motor_in3 2
#define front_motor_in4 7


/*
***forward***
rear_motors_in1 high
rear_motors_in2 low
*/

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

void setupTimer0_PWM() {
  // Set Timer Initial Value to 0
  TCNT0 = 0;

  // Set Compare value (50% duty cycle initially)
  OCR0A = 127;

  // Configure OC0A (Pin 6 on Arduino Uno) as output
  pinMode(6, OUTPUT);

  // Configure timer control register:
  // 1. Fast PWM mode, WGM01=1 & WGM00=1
  // 2. Set OC0A on compare match, clear OC0A at BOTTOM (non-inverted mode), COM0A1=1 & COM0A0=0
  // 3. Clock = F_CPU (no prescaling), CS00=1 CS01=0 CS02=0
  TCCR0A = (1 << WGM00) | (1 << WGM01) | (1 << COM0A1);
  TCCR0B = (1 << CS00);
}


void setup() {
  // put your setup code here, to run once:
  //clock_prescale_set(clock_div_1);
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
  // put your main code here, to run repeatedly:
  digitalWrite(rear_motors_in1, HIGH);
  digitalWrite(rear_motors_in2, LOW);
  setupTimer0_PWM();
}
