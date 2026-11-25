#include "motor.h"

Motor::Motor( void ){
  m_name = "Motor";
  init();
}

Motor::Motor(String name){
  m_name = name;
  init();
}

int Motor::actuate(actuator_event e){
  analogWrite(m_ena_pin, e.throttle);
  analogWrite(m_enb_pin, e.throttle);
  digitalWrite(m_in1_pin, LOW);
  digitalWrite(m_in2_pin, HIGH);
  digitalWrite(m_in3_pin, LOW);
  digitalWrite(m_in4_pin, HIGH);
  return 0;
}

int Motor::init( void ){
  ActuatorBase::init();

  setEnabled(true);
  pinMode(m_in1_pin, OUTPUT);
  pinMode(m_in2_pin, OUTPUT);
  pinMode(m_in3_pin, OUTPUT);
  pinMode(m_in4_pin, OUTPUT);
  pinMode(m_ena_pin, OUTPUT);
  pinMode(m_enb_pin, OUTPUT);
  return 0;
}

int Motor::close( void ){
  return 0;
}