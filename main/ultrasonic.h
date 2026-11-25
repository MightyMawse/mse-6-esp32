#pragma once
#include "shared.h"
#include "sensor_base.h"

#define MACH 0.034

class UltraSonic : public SensorBase{
  public:
    UltraSonic( void );
    ~UltraSonic( void );

    int read( void ) override;
    void setMaxDistance( float max );
  protected:
    int init( void ) override;
    int close( void ) override;
  private:
    float m_duration; // Measured in ms
    float m_distance; // Measured in cm
    float m_max_distance = 0; // Caps around 500
    float m_trig_pin = 16;
    float m_echo_pin = 17;
    float m_frame_length = 0; // Lowers sensitivity
    float m_frame_time = 0;
    float m_timeout = 15; // Time to timeout
    float m_timeout_time = 0;
};