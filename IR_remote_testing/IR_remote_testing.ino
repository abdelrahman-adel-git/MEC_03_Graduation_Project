#include "IR_remote_testing.h"

void get_pressed_key() {
  // put your main code here, to run repeatedly:
  if (IR.decode()) {
    decoded_value = IR.decodedIRData.decodedRawData;
    //Serial.println(decoded_value, HEX);
    switch (decoded_value) {
      case IR_zero:
        IR_pressed_key = decoded_value;
        Serial.println("IR_zero");
        break;
      case IR_one:
        IR_pressed_key = decoded_value;
        Serial.println("IR_one");
        break;
      case IR_two:
        IR_pressed_key = decoded_value;
        Serial.println("IR_two");
        break;
      case IR_three:
        IR_pressed_key = decoded_value;
        Serial.println("IR_three");
        break;
      case IR_four:
        IR_pressed_key = decoded_value;
        Serial.println("IR_four");
        break;
      case IR_five:
        IR_pressed_key = decoded_value;
        Serial.println("IR_five");
        break;
      case IR_six:
        IR_pressed_key = decoded_value;
        Serial.println("IR_six");
        break;
      case IR_seven:
        IR_pressed_key = decoded_value;
        Serial.println("IR_seven");
        break;
      case IR_eight:
        IR_pressed_key = decoded_value;
        Serial.println("IR_eight");
        break;
      case IR_nine:
        IR_pressed_key = decoded_value;
        Serial.println("IR_nine");
        break;
      case IR_up:
        IR_pressed_key = decoded_value;
        Serial.println("IR_up");
        break;
      case IR_down:
        IR_pressed_key = decoded_value;
        Serial.println("IR_down");
        break;
      case IR_right:
        IR_pressed_key = decoded_value;
        Serial.println("IR_right");
        break;
      case IR_left:
        IR_pressed_key = decoded_value;
        Serial.println("IR_left");
        break;
      case IR_ok:
        IR_pressed_key = decoded_value;
        Serial.println("IR_ok");
        break;
      case IR_star:
        IR_pressed_key = decoded_value;
        Serial.println("IR_star");
        break;
      case IR_hash:
        IR_pressed_key = decoded_value;
        Serial.println("IR_hash");
        break;
    }
    delay(200);
    IR.resume();
  }
}
