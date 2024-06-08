#include "Motors.h"

void motors_init() {

  pinMode(rear_motors_ena_pin, OUTPUT);
  pinMode(rear_motors_forward_pin, OUTPUT);
  pinMode(rear_motors_backward_pin, OUTPUT);

  pinMode(steering_motor_enb_pin, OUTPUT);
  pinMode(steering_motor_right_pin, OUTPUT);
  pinMode(steering_motor_left_pin, OUTPUT);

  digitalWrite(rear_motors_forward_pin, LOW);
  digitalWrite(rear_motors_backward_pin, LOW);
  digitalWrite(rear_motors_ena_pin, LOW);

  digitalWrite(steering_motor_right_pin, LOW);
  digitalWrite(steering_motor_left_pin, LOW);
  digitalWrite(steering_motor_enb_pin, LOW);
}

void move(motorsDirection direction, uint8_t speed) {

  OCR0A = speed * 2.55;
  OCR0B = speed * 2.55;
  TCCR0A = (1 << COM0A1) | (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
  TCCR0B = (1 << CS00);
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
      digitalWrite(steering_motor_right_pin, HIGH);
      digitalWrite(steering_motor_left_pin, LOW);

      digitalWrite(rear_motors_forward_pin, LOW);
      digitalWrite(rear_motors_backward_pin, LOW);
      break;
    case MD_left:
      digitalWrite(steering_motor_right_pin, LOW);
      digitalWrite(steering_motor_left_pin, HIGH);

      digitalWrite(rear_motors_forward_pin, LOW);
      digitalWrite(rear_motors_backward_pin, LOW);
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
  OCR0A = 0;
  OCR0B = 0;
}

void center_the_wheels(void) {
  move(MD_right, 65);
  _delay_ms(800);
  move(MD_left, 65);
  _delay_ms(200);
  stop();
}