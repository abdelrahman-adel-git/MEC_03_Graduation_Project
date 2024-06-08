#include "Motors.h"


void motors_init() {

  pinMode(rear_motors_ena_pin, OUTPUT);
  pinMode(rear_motors_forward_pin, OUTPUT);
  pinMode(rear_motors_backward_pin, OUTPUT);


  pinMode(steering_motor_ena_pin, OUTPUT);
  pinMode(steering_motor_right_pin, OUTPUT);
  pinMode(steering_motor_left_pin, OUTPUT);

  digitalWrite(rear_motors_forward_pin, LOW);
  digitalWrite(rear_motors_backward_pin, LOW);
  digitalWrite(rear_motors_ena_pin, LOW);


  digitalWrite(steering_motor_right_pin, LOW);
  digitalWrite(steering_motor_left_pin, LOW);
  digitalWrite(steering_motor_ena_pin, LOW);
}


void servos_init(void) {
  back_middle_servo.attach(back_middle_servo_pin);
  back_middle_servo.write(90);
}

void move(motorsDirection direction, uint8_t rear_speed, uint8_t steering_speed) {

  OCR1A = rear_speed * 2.55;
  OCR4A = steering_speed * 2.55;

  TCCR1A = (1 << COM1A1) | (1 << WGM10);
  TCCR4A = (1 << COM4A1) | (1 << WGM40);


  TCCR1B = (1 << WGM12) | (1 << CS10);
  TCCR4B = (1 << WGM42) | (1 << CS40);
  /*OCR0A = rear_right_speed * 2.55;
  OCR0B = rear_left_speed * 2.55;
  TCCR0A = (1 << COM0A1) | (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
  TCCR0B = (1 << CS00);*/
  //TCCR0B = (1 << CS01);
  //TCCR0B = (1 << CS02);
  switch (direction) {
    case MD_forward:
      digitalWrite(rear_motors_forward_pin, HIGH);
      digitalWrite(rear_motors_backward_pin, LOW);


      digitalWrite(steering_motor_right_pin, LOW);
      digitalWrite(steering_motor_left_pin, LOW);
      break;
    case MD_backward:
      digitalWrite(rear_motors_forward_pin, LOW);
      digitalWrite(rear_motors_backward_pin, HIGH);


      digitalWrite(steering_motor_right_pin, LOW);
      digitalWrite(steering_motor_left_pin, LOW);
      break;
    case MD_right:
      digitalWrite(rear_motors_forward_pin, LOW);
      digitalWrite(rear_motors_backward_pin, LOW);

      digitalWrite(steering_motor_right_pin, HIGH);
      digitalWrite(steering_motor_left_pin, LOW);
      break;
    case MD_left:
      digitalWrite(rear_motors_forward_pin, LOW);
      digitalWrite(rear_motors_backward_pin, LOW);




      digitalWrite(steering_motor_right_pin, LOW);
      digitalWrite(steering_motor_left_pin, HIGH);
      break;
    case MD_forward_right:
      digitalWrite(rear_motors_forward_pin, HIGH);
      digitalWrite(rear_motors_backward_pin, LOW);





      digitalWrite(steering_motor_right_pin, HIGH);
      digitalWrite(steering_motor_left_pin, LOW);
      break;
    case MD_forward_left:
      digitalWrite(rear_motors_forward_pin, HIGH);
      digitalWrite(rear_motors_backward_pin, LOW);





      digitalWrite(steering_motor_right_pin, LOW);
      digitalWrite(steering_motor_left_pin, HIGH);
      break;
    case MD_backward_right:
      digitalWrite(rear_motors_forward_pin, LOW);
      digitalWrite(rear_motors_backward_pin, HIGH);




      digitalWrite(steering_motor_right_pin, HIGH);
      digitalWrite(steering_motor_left_pin, LOW);
      break;
    case MD_backward_left:
      digitalWrite(rear_motors_forward_pin, LOW);
      digitalWrite(rear_motors_backward_pin, HIGH);




      digitalWrite(steering_motor_right_pin, LOW);
      digitalWrite(steering_motor_left_pin, HIGH);
      break;
  }
}

void stop(void) {
  OCR1A = 0;
  OCR4A = 0;


  digitalWrite(rear_motors_forward_pin, HIGH);
  digitalWrite(rear_motors_backward_pin, HIGH);

  digitalWrite(steering_motor_right_pin, HIGH);
  digitalWrite(steering_motor_left_pin, HIGH);
}

void center_the_wheels(void) {
  move(MD_right, 0, 80 - 10);
  _delay_ms(800);
  move(MD_left, 0, 79 - 10);
  _delay_ms(195);
  stop();
}