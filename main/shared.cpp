#include "shared.h"

static uint64_t gpio_bm = 0x00;

int registerPin( int pin ){
  if(!checkPinUsed(pin)){ return 0; }
  uint64_t bitmask = 1 << pin;
  gpio_bm = gpio_bm | bitmask;
  Serial.printf("registerPin() pin %d registered...\n", pin);
  return 1;
}

bool checkPinUsed( int pin ){
  return ((gpio_bm & pin) >> pin) == 0;
}

void clearPin( int pin ){
  uint64_t bitmask = 1 << pin;
  gpio_bm & ~bitmask;
  Serial.printf("clearPin() pin %d cleared...\n", pin);
}