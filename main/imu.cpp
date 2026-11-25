#include "imu.h"

#define LED_BUILTIN 2
#define SCALE_FACTOR 16384
#define GRAVITY 9.81
/* MPU6050 default I2C address is 0x68*/
//MPU6050 mpu(0x69);         //Use for AD0 high
//MPU6050 mpu(0x68, &Wire1); //Use for AD0 low, but 2nd Wire (TWI/I2C) object.

IMU::IMU(){
  m_name = "MPU6050";
  init();
}

int IMU::init( void ){
  SensorBase::init();
  setEnabled(true);

  m_acc = new Vec3();
  m_gy = new Vec3();
  m_offset = new Vec3();

  Wire.begin();

  //Serial.begin(38400); //Initializate Serial wo work well at 8MHz/16MHz

  /*Initialize device and check connection*/ 
  m_mpu.initialize();
  Serial.println("Testing MPU6050 connection...");
  if(m_mpu.testConnection() == false){
    Serial.println("MPU6050 connection failed");
    return -1;
  }
  else{
    Serial.println("MPU6050 connection successful");
  }

  /* Use the code below to change accel/gyro offset values. Use MPU6050_Zero to obtain the recommended offsets */ 
  Serial.println("Updating internal sensor offsets...\n");

  zeroOffsets(); // Set MPU offsets to zero

  //Serial.println("Calibrating IMU...\n");
  //m_mpu.CalibrateAccel();
  //m_mpu.CalibrateGyro();

  /*Configure board LED pin for output*/ 
  pinMode(LED_BUILTIN, OUTPUT);
  return 0;
}

int IMU::read( void ){
  if(!m_enabled){ return -1; }

  m_acc->setX(m_mpu.getAccelerationX());
  m_acc->setY(m_mpu.getAccelerationY());
  m_acc->setZ(m_mpu.getAccelerationZ());

  m_gy->setX(m_mpu.getRotationX());
  m_gy->setY(m_mpu.getRotationY());
  m_gy->setZ(m_mpu.getRotationZ());

  /*Blink LED to indicate activity*/
  blinkState = !blinkState;
  digitalWrite(LED_BUILTIN, blinkState);
  return 0;
}

void IMU::zeroOffsets( void ){
  m_mpu.setXAccelOffset(0); //Set your accelerometer offset for axis X
  m_mpu.setYAccelOffset(0); //Set your accelerometer offset for axis Y
  m_mpu.setZAccelOffset(0); //Set your accelerometer offset for axis Z
  m_mpu.setXGyroOffset(0);  //Set your gyro offset for axis X
  m_mpu.setYGyroOffset(0);  //Set your gyro offset for axis Y
  m_mpu.setZGyroOffset(0);  //Set your gyro offset for axis Z
}

Vec3* IMU::getAcceleration( void ){
  Vec3* pNormal = m_acc;
  pNormal->setX(normalizeAcceleration(abs(m_acc->getX())));
  pNormal->setY(normalizeAcceleration(abs(m_acc->getY())));
  pNormal->setZ(normalizeAcceleration(abs(m_acc->getZ())));
  return pNormal;
}

Vec3* IMU::getGyro( void ){
  return m_gy;
}

float IMU::normalizeAcceleration(float axis){
  return (axis / SCALE_FACTOR) * GRAVITY;
}

int IMU::close( void ){
  return 0;
}