#pragma once
#include "shared.h"

struct actuator_event{
  float throttle;
  float range;
  // TODO: Add event properties as needed
};

class ActuatorBase{
public:
  ActuatorBase() = default;
  ~ActuatorBase() = default;

  String getName(){
    return m_name;
  }

  virtual int actuate( actuator_event e ) = 0;
protected:
  String m_name;
  bool m_enabled = false;

  virtual int init( void ){
    if(Serial){
      Serial.println("Initializing " + m_name + "...");
    }
    return 0;
  }

  virtual int close( void ) = 0;
  void setEnabled(bool state){
    m_enabled = state;
  }
};