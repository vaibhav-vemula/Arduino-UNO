 #include <SoftwareSerial.h>
 #include <Servo.h>
 Servo s1;
 Servo s2;
 Servo s3;
 

 void setup()
 {
  s1.attach(9);
  s2.attach(10);
  s3.attach(11);
  
  Serial.begin(9600);
 
  }
int p=90,q=90,r=90;
  void loop()
  {
    while(Serial.available()> 0 )
    {
      int value = Serial.read();
      
      if(value==1)
      {
        
        p=p+20;
        Serial.print("SERVO 1 : ");
          Serial.println(p);
        for(int pos=p-20;pos<=p;pos++)
        {
          s1.write(pos);
          
          delay(10);
        }
      }
      
      if(value==2) 
      {
         
         p=p-20;
          Serial.print("SERVO 1 : ");
         Serial.println(p);
         for(int pos=p+20;pos>=p;pos--)
         {
        s1.write(pos);
       
         delay(10);
       }
      }
       if(value==3)
      {
        q=q+20;
        Serial.print("SERVO 2 : ");
          Serial.println(q);
        for(int pos=q-20;pos<=q;pos++)
        {
        s2.write(q);
        
          delay(10);
        }
      }
      
      if(value==4) 
      {
         q=q-20;
          Serial.print("SERVO 2 : ");
          Serial.println(q);
         for(int pos=q+20;pos>=q;pos--)
         {
        s2.write(q);
        
          delay(10);
       }}
       
       if(value==5)
      {
        r=r+20;
          Serial.print("SERVO 3 : ");
          Serial.println(r);
        for(int pos=r-20;pos<=r;pos++)
        {
        s3.write(r);
       
          delay(10);
        }
      }
      
      if(value==6) 
      {
         r=r-20;
          Serial.print("SERVO 3 : ");
          Serial.println(r);
         for(int pos=r+20;pos>=r;pos--)
         {
            s3.write(r);
        
          delay(10);
       }}
          
        
     }
 }
              
