#include "Ultrasonic_Sensors.h"

void ultrasonic_sensors_init() {
  /****************front sensors****************/
  pinMode(front_middle_sensor_trig_pin, OUTPUT);
  pinMode(front_middle_sensor_echo_pin, INPUT);

  pinMode(front_right_sensor_trig_pin, OUTPUT);
  pinMode(front_right_sensor_echo_pin, INPUT);

  pinMode(front_left_sensor_trig_pin, OUTPUT);
  pinMode(front_left_sensor_echo_pin, INPUT);
  /*********************************************/

  /****************back sensors*****************/
  pinMode(back_middle_sensor_trig_pin, OUTPUT);
  pinMode(back_middle_sensor_echo_pin, INPUT);

  pinMode(back_right_sensor_trig_pin, OUTPUT);
  pinMode(back_right_sensor_echo_pin, INPUT);

  pinMode(back_left_sensor_trig_pin, OUTPUT);
  pinMode(back_left_sensor_echo_pin, INPUT);
  /**********************************************/

  /****************right sensors*****************/
  pinMode(right_side_front_sensor_trig_pin, OUTPUT);
  pinMode(right_side_front_sensor_echo_pin, INPUT);

  pinMode(right_side_middle_sensor_trig_pin, OUTPUT);
  pinMode(right_side_middle_sensor_echo_pin, INPUT);

  pinMode(right_side_back_sensor_trig_pin, OUTPUT);
  pinMode(right_side_back_sensor_echo_pin, INPUT);
  /**********************************************/

  /****************right sensors*****************/
  pinMode(left_side_front_sensor_trig_pin, OUTPUT);
  pinMode(left_side_front_sensor_echo_pin, INPUT);

  pinMode(left_side_middle_sensor_trig_pin, OUTPUT);
  pinMode(left_side_middle_sensor_echo_pin, INPUT);

  pinMode(left_side_back_sensor_trig_pin, OUTPUT);
  pinMode(left_side_back_sensor_echo_pin, INPUT);
  /**********************************************/
}

void get_sensors_readings() {
  int duration;
  digitalWrite(back_middle_sensor_trig_pin, LOW);
  _delay_us(2);
  digitalWrite(back_middle_sensor_trig_pin, HIGH);
  _delay_us(10);
  digitalWrite(back_middle_sensor_trig_pin, LOW);
  duration = pulseIn(back_middle_sensor_echo_pin, HIGH);
  back_middle_distance = duration * 0.034 / 2;

  Serial.print("back_middle_distance: ");
  Serial.print(back_middle_distance);
  Serial.println(" cm");
}