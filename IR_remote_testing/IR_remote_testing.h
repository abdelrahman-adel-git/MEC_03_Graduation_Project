#ifndef IR_remote_testing_h
#define IR_remote_testing_h
#include <IRremote.h>

typedef enum {
  IR_up = 0xE718FF00,
  IR_down = 0xAD52FF00,
  IR_right = 0xA55AFF00,
  IR_left = 0xF708FF00,
  IR_ok = 0xE31CFF00,
  IR_zero = 0xE619FF00,
  IR_one = 0xBA45FF00,
  IR_two = 0xB946FF00,
  IR_three = 0xB847FF00,
  IR_four = 0xBB44FF00,
  IR_five = 0xBF40FF00,
  IR_six = 0xBC43FF00,
  IR_seven = 0xF807FF00,
  IR_eight = 0xEA15FF00,
  IR_nine = 0xF609FF00,
  IR_star = 0xE916FF00,
  IR_hash = 0xF20DFF00

} IR_remote_key;

IR_remote_key IR_pressed_key;
unsigned long decoded_value;

IRrecv IR(24);
decode_results results;
void IR_get_pressed_key();
#endif