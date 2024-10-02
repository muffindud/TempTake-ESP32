#include <config.h>
#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BMP085.h>
#include <DHT.h>
#include <SoftwareSerial.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);
Adafruit_BMP085 bmp;
DHT dht;
SoftwareSerial HC12(HC_12_RX_PIN, HC_12_TX_PIN);

void setup(){
    Serial.begin(9600);
    HC12.begin(9600);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.display();
}

void loop(){
    if(Serial.available()){
        HC12.write(Serial.read());
    }
    if(HC12.available()){
        Serial.write(HC12.read());
    }
}
