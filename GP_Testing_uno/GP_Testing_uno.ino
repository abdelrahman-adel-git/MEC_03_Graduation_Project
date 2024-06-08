#include "Motors.h"
#include "Ultrasonic_Sensors.h"
#include "util/delay.h"

void setup() {
  Serial.begin(9600);
  motors_init();
  ultrasonic_sensors_init();

  center_the_wheels();
  _delay_ms(1000);
}

void loop() {

  get_sensors_readings();


  if (back_middle_distance <= 20) {
    stop();
  } else {
    move(MD_backward, 65);
  }
}