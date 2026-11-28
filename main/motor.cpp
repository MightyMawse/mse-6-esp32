#include "motor.h"

Motor::Motor( void ){
  m_name = "Motor";
  init();
}

Motor::Motor(String name){
  m_name = name;
  init();
}

void Motor::setInPin( int in1, int in2 ){
  if(registerPin(in1) == 0){
    Serial.printf("Motor::setInPin() pin %d already in use...\n", in1);
    return;
  }

  if(registerPin(in2) == 0){
    Serial.printf("Motor::setInPin() pin %d already in use...\n", in2);
    return;
  }

  m_in1_pin = in1;
  m_in2_pin = in2;
}

void Motor::setEnPin( int en ){
  if(registerPin(en) == 0){
    Serial.printf("Motor::setEnPin() pin %d already in use...\n", en);
    return;
  }

  m_en_pin = en;
}

int Motor::actuate(actuator_event e){
  analogWrite(m_en_pin, e.throttle);

  if(e.direction > 0){
    digitalWrite(m_in1_pin, LOW);
    digitalWrite(m_in2_pin, HIGH);
  }
  else if(e.direction < 0){
    digitalWrite(m_in1_pin, HIGH);
    digitalWrite(m_in2_pin, LOW);
  }
  
  return 0;
}

int Motor::init( void ){
  ActuatorBase::init();

  setEnabled(true);

  if(m_in1_pin == 0 || m_in2_pin == 0 || m_en_pin == 0){
    Serial.println("Motor::init() invalid pin settings...");
    return -1;
  }

  pinMode(m_in1_pin, OUTPUT);
  pinMode(m_in2_pin, OUTPUT);
  pinMode(m_en_pin, OUTPUT);
  return 0;
}

int Motor::close( void ){
  return 0;
}