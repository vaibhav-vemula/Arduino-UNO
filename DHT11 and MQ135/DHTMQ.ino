#include <SimpleDHT.h>

float sensor_volt;
float RS_air; 
float ratio;
float R0=3.35;
int sensorValue;
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop()
{

  Serial.println("DHT11...");
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);
    delay(1000);
    return;
  }
  
  Serial.print("VALUES: ");
  Serial.print((int)temperature); Serial.print(" DEG C, "); 
  Serial.print((int)humidity); Serial.println("H");
  delay(1500);

  
  sensorValue = analogRead(A0);
  sensor_volt=(float)sensorValue/1024*5.0;
  RS_air = (5.0-sensor_volt)/sensor_volt;      
  ratio = RS_air/R0;
    Serial.println("\n"); 
    Serial.println("MQ-135");
    Serial.print("SENSOR VOLT= ");
    Serial.println(sensor_volt);
    Serial.print("RS RATIO = ");
    Serial.println(RS_air);
    Serial.print("Rs/R0 = ");
    Serial.println(ratio);
    Serial.println("==================================");

    Serial.print("\n\n");

    delay(1000);

}
