#include <config.h>
#include <Arduino.h>
#include <Adafruit_BMP085.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <SoftwareSerial.h>


Adafruit_BMP085 bmp;
Adafruit_SSD1306 display(128, 64, &Wire, -1);
DHT dht;
SoftwareSerial HC12(HC_12_RX_PIN, HC_12_TX_PIN);

void setup(){
    Serial.begin(115200);
    HC12.begin(9600);

    display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
    bmp.begin();
    dht.setup(DHT_22_PIN);
    display.display();
    delay(1000);
}

void loop(){
    if(Serial.available()){
        HC12.write(Serial.read());
    }
    if(HC12.available()){
        Serial.write(HC12.read());
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("T: " + String(dht.getTemperature()) + " C");
    display.println("H: " + String(dht.getHumidity()) + " %");
    display.println();
    display.println("P: " + String(bmp.readPressure()) + " Pa");
    display.println("A: " + String(bmp.readAltitude()) + " m");
    display.println("T: " + String(bmp.readTemperature()) + " C");
    display.display();

    delay(1000);
}
