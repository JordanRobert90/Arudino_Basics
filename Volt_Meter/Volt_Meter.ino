//simple volt meter

#define newLED 2
#define okLED 4
#define badLED 6



int analogueValue = 0;
float voltage = 0;
int LedDelay = 2000;

void setup()
{
    pinMode(newLED,OUTPUT);
    pinMode(okLED, OUTPUT);
    pinMode(badLED,OUTPUT);
}

void loop()
{
    analogueValue = analogRead(0);
    voltage = 0.0048*analogueValue;
    if (voltage >= 1.8)
    {
        digitalWrite(newLED, HIGH);
        delay(LedDelay);
        digitalWrite(newLED, LOW);
    }
    else if ((voltage < 1.8) && (voltage > 1.0))
    {
        digitalWrite(okLED, HIGH);
        delay(LedDelay);
        digitalWrite(okLED, LOW);
    }
    else if (voltage <= 1.0)
    {
        digitalWrite(badLED, HIGH);
        delay(LedDelay);
        digitalWrite(badLED, LOW);
    }
}
