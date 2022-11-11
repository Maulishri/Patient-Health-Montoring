#define BLYNK_PRINT Serial

const int LM_35 = A1;  // Assigning Pin to LM35
int input_val = 0;     // TO store input value
float temp = 0;        // To store final temperature output
#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX
    
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>
#include<PulseSensorPlayground.h>
int PulseSensorPurplePin = A0;        
int LED = 12;   
int Signal;                
int Threshold = 555;            
int x,y;
int count =0;
float calories;
float distance;
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "15eadda22aee444ea31812558f59911b";
SoftwareSerial SerialBLE(10, 11); // RX, TX

void setup()
{
  // Debug console
  Serial.begin(9600);

  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);

  Serial.println("Waiting for connections...");
}

void loop()
{
  input_val = analogRead(LM_35);             // Reading analog input
  temp = (5.0 * input_val * 100.0) / 1024;   // Some calculation to convert analog value to temperature
  Serial.print("Temperature is : " );                       
  Serial.println(temp);      
   Signal = analogRead(PulseSensorPurplePin);
   Serial.println(Signal); 
  Blynk.virtualWrite(V5, Signal);
  Blynk.virtualWrite(V4, temp);
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
