#include <Arduino.h>
uint8_t value;

void setup() {
  // put your setup code here, to run once:
  //Set PD7-PD4 as inputs(0x0F)
  DDRD &= 0x0F;
  //enable input pullup
  PORTD |= 0xF0;
  //Set PB3-PB0 as outputs
  DDRB &= 0x0F;

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Reads switch
  value=PIND;
  //set mask to isolate PD7-PD4
  value &= 0xF0;
  //Shift values to the right >>4
  value = value >> 4;
  //invert the value
  value = ~value;
  //Mask value
  value &= 0x0F;
  //Invert again
  value = ~value;
  //Add 1
  value = value + 1;
  //Mask again
  value &= 0x0F;
  //Display the results
  PORTB = value;
  Serial.print("Binary: ");
  Serial.print(value, BIN);
  Serial.print("Decimal: ");
  Serial.println(value);
  delay(250);
}
