#include <WiFi.h>
#include <PubSubClient.h>
#include <Arduino.h>

/*
    Contains the following constants:
    WIFI_SSID
    WIFI_PASS
    MQTT_SERV
    MQTT_PORT
*/
#include "secrets.h"

/*
    Contains the following constants:
    TERMISTOR_PIN
    PHOTORESISTOR_PIN
    ANALOG_READ_RESOLUTION
*/
#include "config.h"

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length){
    for(int i = 0; i < length; i++){
        // TODO
    }
}

void setup(){
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    while(WiFi.status() != WL_CONNECTED){
        delay(500);
    }
    client.setServer(MQTT_SERV, MQTT_PORT);
    client.setCallback(callback);
}

void loop(){
    if(!client.connected()){

    }
    client.loop();
}
