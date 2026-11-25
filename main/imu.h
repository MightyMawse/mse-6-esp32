#pragma once
#include "I2Cdev.h"
#include "MPU6050.h"
#include "shared.h"
#include "sensor_base.h"

class IMU : public SensorBase{
public:
  IMU( void );
  ~IMU( void ) = default;

  int read( void ) override;

  Vec3 *getAcceleration( void );
  Vec3 *getGyro( void );
protected:
  int init( void ) override;
  int close( void ) override;
  void zeroOffsets( void );
private:
  MPU6050 m_mpu;
  Vec3 *m_acc; // Acceleration
  Vec3 *m_gy; // Gyro
  Vec3 *m_offset;
  bool blinkState;

  float normalizeAcceleration(float axis);
};