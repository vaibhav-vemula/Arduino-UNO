void setup()

{
  Serial.begin (9600);
    pinMode(8, OUTPUT);
    pinMode(9, INPUT);
    pinMode(10, OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(12,OUTPUT);
}

void loop()
{

  int t,d;
   digitalWrite(8, LOW);
    delayMicroseconds(2);
   digitalWrite(8, HIGH);
    delayMicroseconds(10);
   digitalWrite(8, LOW);
     t=pulseIn(9, HIGH);
     Serial.println(t);
     t=t/2;
     d=t/29.155;
  if (d<20)
  {
  digitalWrite(11,HIGH);
  analogWrite(10,(20-d)*15);
  analogWrite(12,(20-d)*15);
  
  }
  else
  {
   digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  digitalWrite(12,LOW);
  }
 
  Serial.print(d);
  Serial.println("cm");
  delay(500);

}
