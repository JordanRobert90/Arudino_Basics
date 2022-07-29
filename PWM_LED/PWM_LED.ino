//PWM test on single pin

int d = 2;

void setup()
{
    pinMode(3,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
}

void loop()
{
    for (int a = 1; a < 256; a++)
    {
        analogWrite(3,a);
        delay(d);
        analogWrite(5,a);
        delay(d);
        analogWrite(6,a);
        delay(d);
        analogWrite(9,a);
        delay(d);
        analogWrite(10,a);
        delay(d);
        analogWrite(11,a);
        delay(d);
    }
    for (int a = 255; a >= 0 ; a--)
    {
        analogWrite(3,a);
        delay(d);
        analogWrite(5,a);
        delay(d);
        analogWrite(6,a);
        delay(d);
        analogWrite(9,a);
        delay(d);
        analogWrite(10,a);
        delay(d);
        analogWrite(11,a);
        delay(d);
    }
    delay(200);
}