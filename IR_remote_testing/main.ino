#include "IR_remote_testing.h"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IR.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  get_pressed_key();
}
