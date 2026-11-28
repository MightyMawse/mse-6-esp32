#include "mse_6.h"

MSE6::MSE6( void ){
  init();
}

MSE6::MSE6( String name ){
  m_name = name;
  init();
}

int MSE6::init( void ){
  pImu = new IMU();
  pMotor1 = new Motor("Motor1");
  pMotor2 = new Motor("Motor2");
  pUltrasonic = new UltraSonic();
  // TODO: Add speaker and servo

  pMotor1->setInPin(m_motor1_in1, m_motor1_in2);
  pMotor1->setEnPin(m_motor1_en);

  pMotor2->setInPin(m_motor2_in1, m_motor2_in2);
  pMotor2->setEnPin(m_motor2_en);
  return 0;
}

void MSE6::stateMachine( void ){
  switch(m_state){
    case ST_BOOT:
      break;
    case ST_REPAIR:
      break;
    case ST_WANDER:
      break;
    case ST_COLLIDE:
      break;
    case ST_BACKTRACK:
      break;
    case ST_UPEND:
      break;
  }
}

void MSE6::setState( int state ){
  m_state = state;
}

void MSE6::setName( String name ){
  m_name = name;
}