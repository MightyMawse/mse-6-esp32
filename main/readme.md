State machine behaviour
  - Startup
  - Idle
  - Upended
  - Crash

Functionality
  - motor run at throttle setting
  - steering within 45 degrees
  - differential based on steering angle
  - play voices (clips)
  - rely on web control panel
  - imu for orientation
  - ultrasonic sensing

Class structure
  - SensorBase
    L UltraSonic
    L IMU
  - ActuatorBase
    L Motor
    L Servo
  - Speaker
  - Control

SensorBase()
  L virtual init()
  L virtual read()
  L virtual close()

ActuatorBase
  L virtual init()
  L virtual actuate()

Speaker()
  L init()
  L play()
  L stop()