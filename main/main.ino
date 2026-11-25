#include "shared.h"
#include "imu.h"
#include "ultrasonic.h"
#include "utils.h"
#include "motor.h"

UltraSonic* pUltra;
IMU* pIMU;
Motor* pMotor;

String accelerationLabels[3] = {"X", "Y", "Z"};
String* pLabels;
float distance = 0;
actuator_event event;
String cmd;

int incomingByte = 0;

void setup() {
  Serial.begin(9600);
  delay(2000);

  pLabels = accelerationLabels;
  event.throttle = THROTTLE_ZERO;

  //pUltra = new UltraSonic();
  //pIMU = new IMU();
  pMotor = new Motor("Motor1"); 
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
  pMotor->actuate(event);

  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    char incomingChar = (char)incomingByte;
    cmd += incomingChar;

    if(incomingChar == '$'){
      if(cmd == "FULL$"){
        event.throttle = THROTTLE_FULL;
        Serial.println("Setting full throttle...");
      }
      else if(cmd == "STOP$"){
        event.throttle = THROTTLE_ZERO;
        Serial.println("Setting zero throttle...");
      }
      else if(cmd == "HALF$"){
        event.throttle = THROTTLE_HALF;
        Serial.println("Setting half throttle...");
      }
      cmd = "";
    }
  }
}