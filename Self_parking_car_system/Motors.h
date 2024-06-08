#ifndef MOTORS_H
#define MOTORS_H

#include <Servo.h>


#define rear_motors_ena_pin 11
#define rear_motors_forward_pin 10
#define rear_motors_backward_pin 9

#define steering_motor_ena_pin 6
#define steering_motor_right_pin 4
#define steering_motor_left_pin 3

#define back_middle_servo_pin 22



Servo back_middle_servo;

typedef enum {
  MD_forward,
  MD_backward,
  MD_right,
  MD_left,
  MD_forward_right,
  MD_forward_left,
  MD_backward_right,
  MD_backward_left
} motorsDirection;
void motors_init(void);
void servos_init(void);
void move(motorsDirection direction, uint8_t rear_speed,uint8_t steering_speed);
void stop(void);
void center_the_wheels(void);



#endif /*MOTORS_H*/