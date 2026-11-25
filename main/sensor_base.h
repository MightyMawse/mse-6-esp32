#pragma once
#include "shared.h"

class SensorBase{
public:
    SensorBase() = default;
    ~SensorBase() = default;

    virtual int read( void ) = 0;
    String getName(){
      return m_name;
    }

    void setName(String name){
      m_name = name;
    }
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