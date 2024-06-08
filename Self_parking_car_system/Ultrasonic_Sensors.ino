#include "Ultrasonic_Sensors.h"
#include "util/delay.h"

void timer0_init(void) {
  TCNT0 = 0;
  OCR0A = 250;
  TCCR0A = (1 << WGM01);
  TCCR0B = (1 << FOC0A) | (1 << CS02 | (1 << CS00));
  TIMSK0 = (1 << OCIE0A);
  sei();
}

void timer0_deinit(void) {
  cli();
  TCNT0 = 0;
  OCR0A = 0;
  TCCR0A = 0;
  TCCR0B = 0;
  TIMSK0 = 0;
}

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
  pinMode(right_middle_sensor_trig_pin, OUTPUT);
  pinMode(right_middle_sensor_echo_pin, INPUT);
  /**********************************************/

  /****************right sensors*****************/
  pinMode(left_middle_sensor_trig_pin, OUTPUT);
  pinMode(left_middle_sensor_echo_pin, INPUT);
  /**********************************************/
  timer0_init();
}

void get_sensors_readings(void) {
  int duration;
  /*************************back sensors**********************/
  digitalWrite(back_middle_sensor_trig_pin, LOW);
  _delay_us(2);
  digitalWrite(back_middle_sensor_trig_pin, HIGH);
  _delay_us(10);
  digitalWrite(back_middle_sensor_trig_pin, LOW);
  duration = pulseIn(back_middle_sensor_echo_pin, HIGH,100000);
  back_middle_distance = duration * 0.034 / 2;

  digitalWrite(back_right_sensor_trig_pin, LOW);
  _delay_us(2);
  digitalWrite(back_right_sensor_trig_pin, HIGH);
  _delay_us(10);
  digitalWrite(back_right_sensor_trig_pin, LOW);
  duration = pulseIn(back_right_sensor_echo_pin, HIGH,100000);
  back_right_distance = duration * 0.034 / 2;

  digitalWrite(back_left_sensor_trig_pin, LOW);
  _delay_us(2);
  digitalWrite(back_left_sensor_trig_pin, HIGH);
  _delay_us(10);
  digitalWrite(back_left_sensor_trig_pin, LOW);
  duration = pulseIn(back_left_sensor_echo_pin, HIGH,100000);
  back_left_distance = duration * 0.034 / 2;
  /************************************************************/


  /*************************front sensors**********************/
  digitalWrite(front_middle_sensor_trig_pin, LOW);
  _delay_us(2);
  digitalWrite(front_middle_sensor_trig_pin, HIGH);
  _delay_us(10);
  digitalWrite(front_middle_sensor_trig_pin, LOW);
  duration = pulseIn(front_middle_sensor_echo_pin, HIGH,100000);
  front_middle_distance = duration * 0.034 / 2;

  digitalWrite(front_right_sensor_trig_pin, LOW);
  _delay_us(2);
  digitalWrite(front_right_sensor_trig_pin, HIGH);
  _delay_us(10);
  digitalWrite(front_right_sensor_trig_pin, LOW);
  duration = pulseIn(front_right_sensor_echo_pin, HIGH,100000);
  front_right_distance = duration * 0.034 / 2;

  digitalWrite(front_left_sensor_trig_pin, LOW);
  _delay_us(2);
  digitalWrite(front_left_sensor_trig_pin, HIGH);
  _delay_us(10);
  digitalWrite(front_left_sensor_trig_pin, LOW);
  duration = pulseIn(front_left_sensor_echo_pin, HIGH,100000);
  front_left_distance = duration * 0.034 / 2;
  /************************************************************/

  /*************************right sensors**********************/
  digitalWrite(right_middle_sensor_trig_pin, LOW);
  _delay_us(2);
  digitalWrite(right_middle_sensor_trig_pin, HIGH);
  _delay_us(10);
  digitalWrite(right_middle_sensor_trig_pin, LOW);
  duration = pulseIn(right_middle_sensor_echo_pin, HIGH,100000);
  right_middle_distance = duration * 0.034 / 2;
  /************************************************************/

  /*************************left sensors**********************/
  digitalWrite(left_middle_sensor_trig_pin, LOW);
  _delay_us(2);
  digitalWrite(left_middle_sensor_trig_pin, HIGH);
  _delay_us(10);
  digitalWrite(left_middle_sensor_trig_pin, LOW);
  duration = pulseIn(left_middle_sensor_echo_pin, HIGH,100000);
  left_middle_distance = duration * 0.034 / 2;
  /************************************************************/
}
void print_sensors_readings(void) {
  Serial.print("front_left_distance : ");
  Serial.print(front_left_distance);
  Serial.print(" cm");

  Serial.print("     front_middle_distance: ");
  Serial.print(front_middle_distance);
  Serial.print(" cm");

  Serial.print("      front_right_distance: ");
  Serial.print(front_right_distance);
  Serial.println(" cm");


  Serial.print("left_middle_distance: ");
  Serial.print(left_middle_distance);
  Serial.print(" cm");

  Serial.print("                                       right_middle_distance: ");
  Serial.print(right_middle_distance);
  Serial.println(" cm");



  Serial.print("back_left_distance  : ");
  Serial.print(back_left_distance);
  Serial.print(" cm");

  Serial.print("      back_middle_distance : ");
  Serial.print(back_middle_distance);
  Serial.print(" cm");

  Serial.print("     back_right_distance : ");
  Serial.print(back_right_distance);
  Serial.println(" cm");
  Serial.println("------------------------------------------------------------------------------------------");
}

unsigned int tick = 0;

ISR(TIMER0_COMPA_vect) {
  tick++;
  if (tick == 800) {
    get_sensors_readings();
    //print_sensors_readings();
    tick = 0;
  }
}