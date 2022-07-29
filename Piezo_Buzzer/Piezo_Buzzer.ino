

#define buzzer 3
int del = 500;

void setup()
{
    pinMode(buzzer, OUTPUT);
}

void loop()
{
    analogWrite(buzzer, 200);
    delay(del);
    digitalWrite(buzzer, LOW);
    delay(del);
}