State machine behaviour
  - Startup
  - Idle
  - Upended
  - Crash

Tested Systems:
  - Motor X
  - IMU X
  - Ultrasonic X
  - Servo
  - Lights
  - Speaker

Functionality
  - motor run at throttle setting
  - steering within 45 degrees
  - differential based on steering angle
  - play voices (clips)
  - rely on web control panel
  - imu for orientation
  - ultrasonic sensing
  - flashing leg strips

Class structure
  - SensorBase
    L UltraSonic
    L IMU
  - ActuatorBase
    L Motor
    L Servo
  - Speaker
  - Control
  - Lights

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