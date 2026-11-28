#pragma once
#include "actuator_base.h"

#define THROTTLE_ZERO 0
#define THROTTLE_HALF 128
#define THROTTLE_FULL 255
#define REVERSE -1
#define FORWARD 1

class Motor : public ActuatorBase{
public:
  Motor( void );
  Motor( String name );
  ~Motor( void ) = default;

  int actuate( actuator_event e ) override;
  void setInPin( int in1, int in2 );
  void setEnPin( int en );
protected:
  int init( void ) override;
  int close( void ) override;
private:
  float m_throttle = 0;

  uint64_t m_in1_pin = 16;
  uint64_t m_in2_pin = 17;
  uint64_t m_en_pin = 23;
};