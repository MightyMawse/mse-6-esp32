#pragma once
#include "actuator_base.h"

#define THROTTLE_ZERO 0
#define THROTTLE_HALF 128
#define THROTTLE_FULL 255

class Motor : public ActuatorBase{
public:
  Motor( void );
  Motor( String name );
  ~Motor( void ) = default;

  int actuate( actuator_event e ) override;
protected:
  int init( void ) override;
  int close( void ) override;
private:
  float m_throttle = 0;

  const int m_in1_pin = 16;
  const int m_in2_pin = 17;
  const int m_in3_pin = 5;
  const int m_in4_pin = 18;

  const int m_ena_pin = 23;
  const int m_enb_pin = 22;
};