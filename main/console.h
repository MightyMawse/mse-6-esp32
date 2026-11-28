#pragma once
#include "shared.h"
#include "mse_6.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

class Console{
public:
    Console();
    ~Console() = default;

    void listen( void );
    void init( void );

    // Subsystem monitors
    int monitorIMU( void );
    int monitorUltraSonic( void );
    int monitorMotors( void );
    int monitorSpeaker( void );
    int monitorServo( void );
private:
    const String m_url = "https://localhost:8000/";
    const String m_imu_route = "/imu";
    const String m_us_route = "/ultrasonic";
    const String m_motors_route = "/motors";
    const String m_speaker_route = "/speaker";
    const String m_servo_route = "/servo";
    const char* m_ssid = "sonicwall";
    const char* m_password = "password";
    MSE6* pDroid;
    
    AsyncWebServer server(80);
    AsyncWebSocket ws("/ws");

    int connectNetwork( void );
    int notifyClients( void );
}