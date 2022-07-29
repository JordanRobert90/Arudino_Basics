// knightrider light effects#
int d = 200;

void setup()
{
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
}

void loop()
{
    for (int a = 3; a < 8; a++)
    {
        digitalWrite(a, HIGH);
        delay(d);
        digitalWrite(a, LOW);
        delay(d);
    }

    for (int a = 6; a > 1; a--)
    {
        digitalWrite(a,HIGH);
        delay(d);
        digitalWrite(a,LOW);
        delay(d);
    }
} test