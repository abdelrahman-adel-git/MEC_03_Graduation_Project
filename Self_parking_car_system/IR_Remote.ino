#include "IR_Remote.h"


void IR_remote_init() {
  IR.enableIRIn();
}

void IR_get_pressed_key() {
  // put your main code here, to run repeatedly:
  while (IR_signal_flag == false) {
    if (IR.decode()) {
      decoded_value = IR.decodedIRData.decodedRawData;
      //Serial.println(decoded_value, HEX);
      IR_pressed_key = decoded_value;
      uninterrupted_delay_ms(200);
      IR.resume();
      IR_signal_flag = true;
    }
  }
  IR_signal_flag = false;
}