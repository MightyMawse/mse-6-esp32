#pragma once
#include "shared.h"

int sys_registerPin( int pin );
void sys_clearPin( int pin );
bool sys_checkPinUsed( int pin );