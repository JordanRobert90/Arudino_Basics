//Using a switch to turn on an LED for 1 second

#define LED1 3
#define LED2 5
#define BUTTON 7
int d = 2;

void setup()
{
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(BUTTON, INPUT);
}

void loop()
{
    if (digitalRead(BUTTON)==HIGH)
    {
        for (int a = 1; a < 256; a ++)
        {
            analogWrite(LED1,a);
            delay(d);
            analogWrite(LED2,a);
            delay(d);
        }
        for (int a = 255; a >= 0; a--)
        {
            analogWrite(LED1,a);
            delay(d);
            analogWrite(LED2,a);
            delay(d);
        }
    }
    else
    {
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
    }
}