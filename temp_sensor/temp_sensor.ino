//temp sensor basic

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define HOT 12
#define NORMAL 11
#define COLD 10

DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

float temp = 0.0;

void setup()
{
    Serial.begin(9600);
    dht.begin();
    sensor_t sensor;
    dht.temperature().getSensor(&sensor);
    delayMS = sensor.min_delay / 1000;
    pinMode(HOT, OUTPUT);
    pinMode(NORMAL,OUTPUT);
    pinMode(COLD, OUTPUT);
}

void loop()
{
    // Delay between measurements.
    delay(delayMS);
    // Get temperature event and print its value.
    sensors_event_t event;
    dht.temperature().getEvent(&event);
    Serial.print(F("Temperature: "));
    temp = event.temperature;
    Serial.print(temp);
    Serial.println(F("°C"));

    if (temp >= 25.0)
    {
        digitalWrite(HOT,HIGH);
        delay(5000);
        digitalWrite(HOT,LOW);
    }
    else if (temp > 18.0 && temp <= 24.9)
    {
        digitalWrite(NORMAL,HIGH);
        delay(5000);
        digitalWrite(NORMAL,LOW); 
    }
    else if (temp < 18.0)
    {
        digitalWrite(COLD,HIGH);
        delay(5000);
        digitalWrite(COLD,LOW);
    }
}
