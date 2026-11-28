#include "system.h"

static uint64_t gpio_bm = 0x00;

int sys_registerPin( int pin ){
  if(!sys_checkPinUsed(pin)){ return 0; }
  uint64_t bitmask = 1 << pin;
  gpio_bm = gpio_bm | bitmask;
  Serial.printf("System::sys_registerPin() pin %d registered...\n", pin);
  return 1;
}

bool sys_checkPinUsed( int pin ){
  return ((gpio_bm & pin) >> pin) == 0;
}

void sys_clearPin( int pin ){
  uint64_t bitmask = 1 << pin;
  gpio_bm & ~bitmask;
  Serial.printf("System::sys_clearPin() pin %d cleared...\n", pin);
}