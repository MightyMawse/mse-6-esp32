#include "console.h"

Console::Console(){
    Console::init();
}

void Console::init( void ){
    Console::connectNetwork();
}

int Console::connectNetwork( void ){
    WiFi.begin(m_ssid, m_password);
    Serial.println("Connecting");
    // TODO: Make failure an option
    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to WiFi network with IP Address: ");
    Serial.println(WiFi.localIP());
    return 0;
}

// Send comm
void Console::listen( void ){

}

int Console::monitorIMU( void ){
    return 0;
}

int Console::monitorUltraSonic( void ){
    return 0;
}

int Console::monitorMotors( void ){
    return 0;
}

int Console::monitorSpeaker( void ){
    return 0;
}

int Console::monitorServo( void ){
    return 0;
}

int Console::notifyClients( void ){
    ws
    return 0;
}