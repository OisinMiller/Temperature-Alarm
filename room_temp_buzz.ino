const int B=4275;                 // B value of the thermistor
const int R0 = 100000;            // R0 = 100k
const int pinTempSensor = A0;     // Grove - Temperature Sensor connect to A0
#include "rgb_lcd.h"
#include <Wire.h>
rgb_lcd lcd;
char devid[] = "vDC23001313889A3";
char serverName[] = "api.pushingbox.com";
boolean DEBUG = true;
#include <Bridge.h>
#include <HttpClient.h>
const int buttonPin = 8; 
int buttonState = 0; 



void setup()
{
      lcd.begin(16, 2);
      Serial.begin(9600);
      pinMode(4, OUTPUT);
      pinMode(13, OUTPUT);
      digitalWrite(13, LOW);
      Bridge.begin();
      digitalWrite(13, HIGH);
      Serial.begin(9600);
      while (!Serial); // wait for a serial connection

      

     
}

void loop()
{
    
    int a = analogRead(pinTempSensor );
    

    float R = 1023.0/((float)a)-1.0;
    R = 100000.0*R;

    float temperature=1.0/(log(R/100000.0)/B+1/298.15)-273.15;
    Serial.print("temperature = ");
    Serial.println(temperature);

    delay(200);

   
    if (temperature > 26)
    {
      pinMode(6, OUTPUT);
      digitalWrite(6, HIGH);
        delay(analogRead(0));
      digitalWrite(6, LOW);
      digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);                       // wait for a second
      digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);                       // wait for a second

      HttpClient client;
      
          String APIRequest;
          APIRequest = String(serverName) + "/pushingbox?devid=" + String(devid)+ "&IDtag=100&TimeStamp=50&TempC=";
          client.get (APIRequest);
            delay(10000);
    }

 
        // wait a bit for the entire message to arrive
            delay(1000);
        // clear the screen
           
           
           lcd.print(temperature );
           lcd.print(" \n ");

              



}

