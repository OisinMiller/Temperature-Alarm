const int B=4275;                 // B value of the thermistor
const int R0 = 100000;            // R0 = 100k
const int pinTempSensor = A0;     // Grove - Temperature Sensor connect to A0


void setup()
{
    Serial.begin(9600);
     pinMode(4, OUTPUT);
}

void loop()
{
    int a = analogRead(pinTempSensor );

    float R = 1023.0/((float)a)-1.0;
    R = 100000.0*R;

    float temperature=1.0/(log(R/100000.0)/B+1/298.15)-273.15;//convert to temperature via datasheet ;

    Serial.print("temperature = ");
    Serial.println(temperature);

    delay(200);
    if (temperature > 21)
    {
       pinMode(6, OUTPUT);
      digitalWrite(6, HIGH);
 delay(analogRead(0));
 digitalWrite(6, LOW);
  digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
 digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
    }
}


