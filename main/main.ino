#include "shared.h"
#include "imu.h"
#include "ultrasonic.h"
#include "utils.h"
#include "motor.h"

UltraSonic* pUltra;
IMU* pIMU;
Motor* pMotor1;
Motor* pMotor2;

String accelerationLabels[3] = {"X", "Y", "Z"};
String* pLabels;

float distance = 0;
actuator_event event;

void startupMessage();

void setup() {
  Serial.begin(9600);
  delay(2000);
  startupMessage();

  pLabels = accelerationLabels;
  
  event.throttle = THROTTLE_HALF;
  event.direction = REVERSE;

  //pUltra = new UltraSonic();
  //pIMU = new IMU();
  pMotor1 = new Motor("Motor1"); 
  pMotor1->setEnPin(23);
  pMotor1->setInPin(16, 17);

  pMotor2 = new Motor("Motor2");
  pMotor2->setEnPin(22);
  pMotor2->setInPin(18, 5);
}

void loop() {
  // Ultrasonic
  /*
  distance = pUltra->read();
  if(distance > 0){
    Serial.println(pUltra->getName() + ' ' + distance);
  }
  */

  // IMU
  //pIMU->read();
  //Serial.println(util_vecToString(pIMU->getAcceleration(), pLabels));
  //delay(500);

  // Motor
  pMotor1->actuate(event);
  pMotor2->actuate(event);
}

void startupMessage(){
  Serial.println("========================================");
  Serial.println("  MSE-6 SERIES REPAIR DROID");
  Serial.println("  Property of Mason McInerney @ Exponential Labs");
  Serial.println("========================================");
}