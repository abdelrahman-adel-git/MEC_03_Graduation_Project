#ifndef ULTRASONIC_SENSORS_H
#define ULTRASONIC_SENSORS_H


/****************front sensors****************/
#define front_middle_sensor_trig_pin 30
#define front_middle_sensor_echo_pin 31

#define front_right_sensor_trig_pin 8
#define front_right_sensor_echo_pin 7

#define front_left_sensor_trig_pin 28
#define front_left_sensor_echo_pin 29
/*********************************************/

/****************back sensors*****************/
#define back_middle_sensor_trig_pin 34
#define back_middle_sensor_echo_pin 35

#define back_right_sensor_trig_pin 32
#define back_right_sensor_echo_pin 33

#define back_left_sensor_trig_pin 36
#define back_left_sensor_echo_pin 37
/**********************************************/

/****************right sensors*****************/
#define right_middle_sensor_trig_pin 14
#define right_middle_sensor_echo_pin 15
/**********************************************/

/****************left sensors*****************/
#define left_middle_sensor_trig_pin 26
#define left_middle_sensor_echo_pin 27
/**********************************************/

/***********************************************/

volatile int front_middle_distance = 0;
volatile int front_right_distance = 0;
volatile int front_left_distance = 0;

volatile int back_middle_distance = 0;
volatile int back_right_distance = 0;
volatile int back_left_distance = 0;

volatile int right_middle_distance = 0;
volatile int left_middle_distance = 0;

void timer0_init(void);
void timer0_de_init(void);
void ultrasonic_sensors_init(void);
void get_sensors_readings(void);


#endif /*ULTRASONIC_SENSORS_H*/