#ifndef MOTORS_H
#define MOTORS_H

#define rear_motors_ena_pin 6
#define rear_motors_forward_pin 4
#define rear_motors_backward_pin 3

#define steering_motor_enb_pin 5
#define steering_motor_right_pin 2
#define steering_motor_left_pin 7

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
void move(motorsDirection direction, uint8_t speed);
void stop(void);
void center_the_wheels(void);



#endif /*MOTORS_H*/