#pragma once
#include <Wire.h>
#include <Arduino.h>

class Vec3{
  public:
    Vec3( void ) = default;
    Vec3(int16_t x, int16_t y, int16_t z){
      m_x = x;
      m_y = y;
      m_z = z;
    }
    ~Vec3( void ) = default;

    int16_t getX( void ) { return m_x; }
    int16_t getY( void ) { return m_y; }
    int16_t getZ( void ) { return m_z; }
    void setX( int16_t x ) { m_x = x; }
    void setY( int16_t y ) { m_y = y; }
    void setZ( int16_t z ) { m_z = z; }
  private:
    int16_t m_x = 0;
    int16_t m_y = 0;
    int16_t m_z = 0;
};