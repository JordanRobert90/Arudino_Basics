//Traffic light simulation

#define westButton 3
#define eastButton 13
#define westRed 2
#define westAmber 1
#define westGreen 0
#define eastRed 12
#define eastAmber 11
#define eastGreen 10

#define AmberBlinkTime 500 //defines amber blinks for 0.5 seconds

boolean trafficWest = true; //west = true, east = false
int flowTime = 10000; //amount of time to let traffic flow
int changeDelay = 2000; //amount of time between colour changes

void setup()
{
    //set the digital IO pins up
    pinMode(westButton, INPUT);
    pinMode(eastButton, INPUT);
    pinMode(westRed, OUTPUT);
    pinMode(westAmber, OUTPUT);
    pinMode(westGreen, OUTPUT);
    pinMode(eastRed, OUTPUT);
    pinMode(eastAmber, OUTPUT);
    pinMode(eastGreen, OUTPUT);
    //Set initial Light Setup
    digitalWrite(westRed, LOW);
    digitalWrite(westAmber, LOW);
    digitalWrite(westGreen, HIGH);
    digitalWrite(eastRed, HIGH);
    digitalWrite(eastAmber, LOW);
    digitalWrite(eastGreen, LOW);
}

void loop()
{
    if (digitalRead(westButton)==HIGH)
    {
        if(trafficWest != true)
        {
            trafficWest = true;
            delay(flowTime);
            digitalWrite(eastGreen, LOW);
            digitalWrite(eastAmber, HIGH);
            delay(changeDelay);
            digitalWrite(eastAmber, LOW);
            digitalWrite(eastRed, HIGH);
            delay(changeDelay);
            for (int a = 0; a < 5; a ++)
            {
                digitalWrite(westAmber, LOW);
                delay(AmberBlinkTime);
                digitalWrite(westAmber,HIGH);
                delay(AmberBlinkTime);
            }
            digitalWrite(westAmber, LOW);
            digitalWrite(westRed, LOW);
            digitalWrite(westGreen, HIGH);
        }
    }
    if (digitalRead(eastButton)==HIGH)
    {
        if(trafficWest == true)
        {
            trafficWest = false;
            delay(flowTime);
            digitalWrite(westGreen, LOW);
            digitalWrite(westAmber, HIGH);
            delay(changeDelay);
            digitalWrite(westAmber, LOW);
            digitalWrite(westRed, HIGH);
            delay(changeDelay);
            for (int a = 0; a < 5; a ++)
            {
                digitalWrite(eastAmber, LOW);
                delay(AmberBlinkTime);
                digitalWrite(eastAmber, HIGH);
                delay(AmberBlinkTime);
            }
            digitalWrite(eastAmber, LOW);
            digitalWrite(eastRed, LOW);
            digitalWrite(eastGreen, HIGH);
        }
    }
}