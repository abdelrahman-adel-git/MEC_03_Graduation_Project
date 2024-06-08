#ifndef ULTRASONIC_SENSORS_H
#define ULTRASONIC_SENSORS_H


/****************front sensors****************/
#define front_middle_sensor_trig_pin 0
#define front_middle_sensor_echo_pin 0

#define front_right_sensor_trig_pin 0
#define front_right_sensor_echo_pin 0

#define front_left_sensor_trig_pin 0
#define front_left_sensor_echo_pin 0
/*********************************************/

/****************back sensors*****************/
#define back_middle_sensor_trig_pin 9
#define back_middle_sensor_echo_pin 10

#define back_right_sensor_trig_pin 0
#define back_right_sensor_echo_pin 0

#define back_left_sensor_trig_pin 0
#define back_left_sensor_echo_pin 0
/**********************************************/

/****************right sensors*****************/
#define right_side_front_sensor_trig_pin 0
#define right_side_front_sensor_echo_pin 0

#define right_side_middle_sensor_trig_pin 0
#define right_side_middle_sensor_echo_pin 0

#define right_side_back_sensor_trig_pin 0
#define right_side_back_sensor_echo_pin 0
/**********************************************/

/*****************left sensors*****************/
#define left_side_front_sensor_trig_pin 0
#define left_side_front_sensor_echo_pin 0

#define left_side_middle_sensor_trig_pin 0
#define left_side_middle_sensor_echo_pin 0

#define left_side_back_sensor_trig_pin 0
#define left_side_back_sensor_echo_pin 0
/***********************************************/

int front_middle_distance = 0;
int front_right_distance = 0;
int front_left_distance = 0;

int back_middle_distance = 0;
int back_right_distance = 0;
int back_left_distance = 0;

int right_side_front_distance = 0;
int right_side_middle_distance = 0;
int right_side_back_distance = 0;

int left_side_front_distance = 0;
int left_side_middle_distance = 0;
int left_side_back_distance = 0;

void ultrasonic_sensors_init(void);
void get_sensors_readings(void);


#endif /*ULTRASONIC_SENSORS_H*/