#pragma once
#include "shared.h"
#include "motor.h"
#include "ultrasonic.h"
#include "imu.h"
#include "actuator_base.h"

// State machine states
#define ST_BOOT 0 // Initial state for booting and initialisation
#define ST_REPAIR 1 // Override state for remaining on but with no behaviour
#define ST_WANDER 2 // Main state of wandering around
#define ST_COLLIDE 3 // Upon colliding with something
#define ST_BACKTRACK 4 // After collision, reverse up and find a new path
#define ST_UPEND 5 // If tipped/picked up

class MSE6{
public:
  MSE6( void );
  MSE6( String name );
  ~MSE6( void ) = default;

  int init( void );
  void stateMachine( void ); // Called on loop
  void setState( int state );
  void setName( String name );
  
private:
  String m_name = "MSE-6";
  int m_state = BOOT;

  const int m_motor1_in1 = 16;
  const int m_motor1_in2 = 17;
  const int m_motor1_en = 23;

  const int m_motor2_in1 = 18;
  const int m_motor2_in2 = 5;
  const int m_motor2_en = 22;

  actuator_event m_event;

  Motor *pMotor1;
  Motor *pMotor2;
  IMU *pImu;
  UltraSonic *pUltrasonic;
  //Speaker *pSpeaker;
  //Servo *pServo;
}