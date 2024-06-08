#include "Auto_Parking.h"
#include "Motors.h"
#include "Ultrasonic_Sensors.h"
#include "IR_Remote.h"
#include "util/delay.h"
#include "avr/interrupt.h"

void setup() {
  Serial.begin(9600);
  motors_init();
  servos_init();
  //ultrasonic_sensors_init();
  IR_remote_init();
  uninterrupted_center_the_wheels();
  //timer0_deinit();
}

void loop() {
  IR_get_pressed_key();
  switch (IR_pressed_key) {
    case IR_one:
      ultrasonic_sensors_init();
      search_for_left_vertical_parking_slot();
      break;
    case IR_two:
      ultrasonic_sensors_init();
      search_for_left_parallel_parking_slot();
      break;
    case IR_three:
      ultrasonic_sensors_init();
      search_for_left_angle_parking_slot();
      break;
    case IR_ok:
      ultrasonic_sensors_init();
      break;
  }
}