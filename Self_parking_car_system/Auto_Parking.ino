/********************************************************************Includes*******************************************************************/

#include "Motors.h"
#include "Ultrasonic_Sensors.h"
#include "IR_Remote.h"
#include "util/delay.h"
#include "avr/interrupt.h"

/***********************************************************************************************************************************************/

/********************************************************************Variables******************************************************************/

uint8_t rear_speed = 53 + 2 + 1;
uint8_t steering_speed = 70;

/***********************************************************************************************************************************************/


/************************************************************Uninterrupted Functions************************************************************/

void uninterrupted_delay_ms(const int interval) {
  cli();  // Disable interrupts
  for (int i = 0; i < interval; ++i) {
    _delay_ms(1);  // Delay without interruption, loop for 'interval' milliseconds
  }
  sei();  // Enable interrupts
}

/*-----------------------------------------------------------------------------------------------*/

void uninterrupted_center_the_wheels(void) {
  cli();
  center_the_wheels();
  sei();
}

/*-----------------------------------------------------------------------------------------------*/

/***********************************************************************************************************************************************/

/***************************************************************Parking Functions***************************************************************/

void search_for_left_vertical_parking_slot(void) {

  //back_middle_servo.write(160);

  move(MD_forward, rear_speed + 2, steering_speed);
  while (1) {
    if (front_left_distance > 45 && left_middle_distance > 45) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }


  move(MD_forward_right, rear_speed + 6, steering_speed);
  uninterrupted_delay_ms(2000);
  move(MD_forward_right, rear_speed + 4, steering_speed);
  uninterrupted_delay_ms(2400);

  stop();
  uninterrupted_delay_ms(1000);

  move(MD_backward_left, rear_speed + 5, steering_speed);
  back_middle_distance = 100;
  while (1) {
    if (back_middle_distance < 45) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }


  uninterrupted_center_the_wheels();
  uninterrupted_delay_ms(500);
  int right_side_adjustment_counter = 0;
  int left_side_adjustment_counter = 0;
  back_middle_distance += 100;
  for (;;) {
    move(MD_backward, rear_speed + 3, steering_speed);

    if (back_middle_distance < 20) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    } else if (back_right_distance < 4) {
      adjust_right_side_of_car();
      back_right_distance += 10;
      right_side_adjustment_counter++;
    } else if (back_left_distance < 4) {
      adjust_left_side_of_car();
      back_left_distance += 10;
      left_side_adjustment_counter++;
    }
  }

  /*uninterrupted_center_the_wheels();
  uninterrupted_delay_ms(500);
  while (1) {
    move(MD_backward, rear_speed + 3, steering_speed);

    if (back_middle_distance < 15) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }*/









  /* back_middle_distance = 50;
  while (1) {
    if (back_middle_distance > 140) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }

  uninterrupted_center_the_wheels();
  uninterrupted_delay_ms(500);
  move(MD_backward, rear_speed + 3, steering_speed);
  while (1) {
    if (back_left_distance <= 10 || back_middle_distance <= 40) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }

  back_middle_servo.write(120);
  move(MD_forward_right, rear_speed + 3, steering_speed);
  back_middle_distance = 50;
  while (1) {
    if (back_middle_distance > 160) {
      uninterrupted_delay_ms(1000);
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }


  //back_middle_servo.write(90);
  move(MD_backward_left, rear_speed + 3, steering_speed);
  back_middle_distance = 150;
  while (1) {
    if (back_middle_distance < 90) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }*/

  /*move(MD_forward_right, rear_speed + 3, steering_speed);
  while (1) {
    if (back_middle_distance > 130) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }


  move(MD_backward_left, rear_speed + 3, steering_speed);
  while (1) {
    if (back_middle_distance < 110) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }

  move(MD_forward_right, rear_speed + 3, steering_speed);
  while (1) {
    if (back_middle_distance > 130) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }*/


  /*back_middle_servo.write(150);
  move(MD_forward_right, rear_speed + 3, steering_speed);
  uninterrupted_delay_ms(10);
  while (1) {
    if (back_left_distance > 45) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }

  back_middle_distance -= 100;
  move(MD_forward_right, rear_speed + 3, steering_speed);
  while (1) {
    if (back_middle_distance > 70) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }



  back_middle_servo.write(135);
  move(MD_backward_left, rear_speed + 3, steering_speed);
  back_middle_distance += 100;
  uninterrupted_delay_ms(1000);
  while (1) {
    if (back_middle_distance < 120) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }

  move(MD_backward_left, rear_speed + 3, steering_speed);
  uninterrupted_delay_ms(1000);
  while (1) {
    if (back_middle_distance < 110) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }

  back_middle_servo.write(90);
  move(MD_forward_right, rear_speed + 5, steering_speed);
  uninterrupted_delay_ms(1000);
  while (1) {
    if (back_middle_distance > 140) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }

  back_middle_servo.write(90);
  move(MD_backward_left, rear_speed + 5, steering_speed);
  uninterrupted_delay_ms(1500);
  while (1) {
    if (back_middle_distance < 115) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }



  back_middle_servo.write(90);
  uninterrupted_center_the_wheels();
  uninterrupted_delay_ms(500);
  int right_side_adjustment_counter = 0;
  int left_side_adjustment_counter = 0;
  back_middle_distance += 100;
  while (1) {
    move(MD_backward, rear_speed + 3, steering_speed);

    if (back_middle_distance < 25) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    } else if (back_right_distance < 4) {
      adjust_right_side_of_car();
      back_right_distance += 10;
      right_side_adjustment_counter++;
    } else if (back_left_distance < 4) {
      adjust_left_side_of_car();
      back_left_distance += 10;
      left_side_adjustment_counter++;
    }
  }*/
  /*uninterrupted_center_the_wheels();
  while (1) {
    move(MD_backward, rear_speed + 3, steering_speed);

    if (back_middle_distance < 15) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }*/

  stop();
  uninterrupted_delay_ms(20000);
}

/*-----------------------------------------------------------------------------------------------*/

/*void search_for_left_angle_parking_slot(void) {

  back_middle_servo.write(150);
  move(MD_forward, rear_speed + 2, steering_speed);
  while (1) {
    if (back_left_distance > 100 && left_middle_distance > 100) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }

  move(MD_backward_left, rear_speed + 2, steering_speed);
  while (1) {
    if (back_left_distance < 30) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }



  move(MD_forward_right, rear_speed + 2, steering_speed);
  while (1) {
    if (back_left_distance > 100) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }

  move(MD_forward_right, rear_speed + 2, steering_speed);
  while (1) {
    if (back_middle_distance > 100) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }

  back_middle_servo.write(130);
  move(MD_backward_left, rear_speed + 2, steering_speed);
  while (1) {
    if (back_middle_distance < 40) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }

  back_middle_servo.write(120);

  move(MD_forward_right, rear_speed + 2, steering_speed);
  while (1) {
    if (back_middle_distance > 150) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }


  back_middle_servo.write(45);
  move(MD_backward_left, rear_speed + 2, steering_speed);
  while (1) {
    if (back_middle_distance < 35) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }

  back_middle_servo.write(90);
  move(MD_forward_right, rear_speed + 2, steering_speed);
  while (1) {
    if (back_middle_distance > 100) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }


  stop();
  uninterrupted_center_the_wheels();
  uninterrupted_delay_ms(20000);
}*/

void search_for_left_angle_parking_slot(void) {

  move(MD_forward, rear_speed + 2, steering_speed);
  while (1) {
    if (back_left_distance > 110 && left_middle_distance > 70) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }


  move(MD_backward, rear_speed + 2, steering_speed);
  while (1) {
    if (back_left_distance < 75) {
      /*stop();
      uninterrupted_delay_ms(1000);*/
      break;
    }
  }


  move(MD_backward, rear_speed + 2, steering_speed);
  while (1) {
    if (left_middle_distance < 75) {
      /*stop();
      uninterrupted_delay_ms(1000);*/
      break;
    }
  }
  front_right_distance += 100;
  move(MD_backward, rear_speed + 2, steering_speed);
  while (1) {
    if (front_left_distance < 70) {
      uninterrupted_delay_ms(1600);
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }



  move(MD_forward_left, rear_speed + 2, steering_speed);
  while (1) {
    if (front_middle_distance < 20 || front_left_distance < 20) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }



  stop();
  uninterrupted_center_the_wheels();
  uninterrupted_delay_ms(20000);
}

/*-----------------------------------------------------------------------------------------------*/

void search_for_left_parallel_parking_slot(void) {


  move(MD_forward, rear_speed + 2, steering_speed);
  while (1) {
    if (front_left_distance > 45 && back_left_distance > 45) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }

  back_middle_servo.write(110);

  move(MD_forward, rear_speed + 2, steering_speed);
  //uninterrupted_delay_ms(1000);
  while (1) {
    if (back_left_distance < 35) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }

  move(MD_forward_right, rear_speed + 2, steering_speed);
  uninterrupted_delay_ms(1000);
  stop();
  uninterrupted_delay_ms(1000);

  move(MD_backward_left, rear_speed + 4, steering_speed);
  uninterrupted_delay_ms(3000);
  move(MD_backward_left, rear_speed + 2, steering_speed);
  //uninterrupted_delay_ms(1000);
  while (1) {
    if (back_middle_distance < 65) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }

  back_middle_servo.write(45);
  move(MD_backward_right, rear_speed + 2, steering_speed);
  //uninterrupted_delay_ms(1000);
  while (1) {
    if (back_middle_distance < 16 || back_left_distance < 10) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }

  back_middle_servo.write(90);
  move(MD_forward_left, rear_speed + 2 - 2, steering_speed);
  while (1) {
    if (back_middle_distance > 28 || front_middle_distance < 10 || front_left_distance < 10) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }

  back_middle_servo.write(80);
  for (int i = 0; i < 1; i++) {

    move(MD_backward_right, rear_speed + 2 - 2, steering_speed);
    while (1) {
      if (back_middle_distance < 20 || back_right_distance < 10) {
        stop();
        uninterrupted_delay_ms(1000);
        break;
      }
    }

    if (front_left_distance - back_left_distance >= 3) {
      move(MD_forward_left, rear_speed + 2 - 2, steering_speed);
      while (1) {
        if (back_middle_distance > 30 || front_middle_distance < 10) {
          stop();
          uninterrupted_delay_ms(1000);
          break;
        }
      }
    }
  }


  /*if (front_middle_distance > 25) {
    move(MD_backward_right, rear_speed + 2 - 2, steering_speed);
    while (1) {
      if (back_middle_distance < 12 || back_right_distance < 10) {
        stop();
        uninterrupted_delay_ms(1000);
        break;
      }
    }

    move(MD_forward_left, rear_speed + 2 - 2, steering_speed);
    while (1) {
      if (back_middle_distance > 20 || front_middle_distance < 10) {
        stop();
        uninterrupted_delay_ms(1000);
        break;
      }
    }
  }*/
  uninterrupted_center_the_wheels();
  move(MD_backward, rear_speed + 2 - 2, steering_speed);
  while (1) {
    if (back_middle_distance < 17) {
      stop();
      uninterrupted_delay_ms(1000);
      break;
    }
  }

  if (front_left_distance - back_left_distance >= 3) {

    move(MD_forward_left, rear_speed + 2 - 2, steering_speed);
    while (1) {
      if (back_middle_distance > 30 || front_middle_distance < 10) {
        stop();
        uninterrupted_delay_ms(1000);
        break;
      }
    }

    uninterrupted_center_the_wheels();
    move(MD_backward, rear_speed + 2 - 2, steering_speed);
    while (1) {
      if (back_middle_distance < 17) {
        stop();
        uninterrupted_delay_ms(1000);
        break;
      }
    }
  }

  stop();
  uninterrupted_delay_ms(20000);
}

/*-----------------------------------------------------------------------------------------------*/

void adjust_right_side_of_car(void) {
  stop();
  uninterrupted_delay_ms(1000);

  move(MD_forward_right, rear_speed + 3, steering_speed);
  uninterrupted_delay_ms(1500);

  stop();
  uninterrupted_delay_ms(1000);
  uninterrupted_center_the_wheels();
  uninterrupted_delay_ms(500);
}

/*-----------------------------------------------------------------------------------------------*/

void adjust_left_side_of_car(void) {
  stop();
  uninterrupted_delay_ms(1000);

  move(MD_forward_left, rear_speed + 3, steering_speed);
  uninterrupted_delay_ms(1500);

  stop();
  uninterrupted_delay_ms(1000);
  uninterrupted_center_the_wheels();
  uninterrupted_delay_ms(500);
}

/*-----------------------------------------------------------------------------------------------*/

/***********************************************************************************************************************************************/