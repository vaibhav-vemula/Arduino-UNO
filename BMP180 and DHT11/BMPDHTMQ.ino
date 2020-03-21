#include <SimpleDHT.h>
#include <Arduino.h>
#include <Wire.h>
#include <BMP180I2C.h>


float sensor_volt;
float RS_air; 
float ratio; 
float R0=3.35;
int sensorValue;
int pinDHT11 = 2;

#define I2C_ADDRESS 0x77
BMP180I2C bmp180(I2C_ADDRESS);
SimpleDHT11 dht11(pinDHT11);
void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);

  while (!Serial);
  Wire.begin();
  
  if (!bmp180.begin())
  {
     Serial.println("begin() failed. check your BMP180 Interface and I2C Address.");
     while (1);
  }
  bmp180.resetToDefaults();
  bmp180.setSamplingMode(BMP180MI::MODE_UHR);

}

void loop()
{
  Serial.println("DHT11...");
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
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

 if (!bmp180.measureTemperature())
 {
   Serial.println("could not start temperature measurement");
   return;
 }
 do
 {
  delay(100);
 }
  while (!bmp180.hasValue());

  Serial.print("Temperature from bmp: ");
  Serial.print(bmp180.getTemperature());
  Serial.println(" degC");

  if (!bmp180.measurePressure())
  {
    Serial.println("could not start perssure measurement");
    return;
  }
  do
  {
   delay(100);
  }
  while (!bmp180.hasValue());

  Serial.print("Pressure: ");
  Serial.print(bmp180.getPressure());
  Serial.println(" Pa");

}
