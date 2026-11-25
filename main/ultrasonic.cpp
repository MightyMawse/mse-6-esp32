#include "ultrasonic.h"

UltraSonic::UltraSonic(){
  m_name = "HC-SR04";
  init();
}

void UltraSonic::setMaxDistance(float max){
  m_max_distance = max;
}

int UltraSonic::init( void ){
  SensorBase::init();

  setEnabled(true);
  pinMode(m_trig_pin, OUTPUT);
  pinMode(m_echo_pin, INPUT);
  pinMode(m_echo_pin, INPUT_PULLDOWN);
  return 0;
}

int UltraSonic::read( void ){
  if(!m_enabled) { return -1; }

  if(m_frame_time >= m_frame_length){
    m_frame_time = 0;

    digitalWrite(m_trig_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(m_trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(m_trig_pin, LOW);

    m_duration = pulseIn(m_echo_pin, HIGH);
    m_distance = (m_duration * MACH) / 2;

    if(m_duration == 0){
      m_timeout_time++;
      if(m_timeout_time >= m_timeout){
        setEnabled(false);
        Serial.println("Warning " + m_name + " May be Offline...");
      }
    }
    else{
      m_timeout_time = 0;
    }
  }
  else{
    m_frame_time++;
  }
    
  if(m_distance >= m_max_distance && m_max_distance > 0){
    return m_max_distance;
  }
  return m_distance;
}

int UltraSonic::close( void ){
  Serial.println("Closing " + m_name + "...");
  setEnabled(false);
  return 0;
}