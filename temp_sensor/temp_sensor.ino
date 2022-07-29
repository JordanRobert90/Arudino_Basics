//temp sensor basic

#include "Adafruit_Sensor.h"
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

void setup()
{
    Serial.begin(9600);
    dht.begin();
    
}

void loop()
{
    Serial.println();
}
