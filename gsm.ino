 #include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);

void setup()
{
  mySerial.begin(9600);   //baud rate of GSM Module  
  Serial.begin(9600);    //baud rate of Serial Monitor (Arduino)
  delay(100);
}


void loop()
{
  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 's':
      SendMessage();
      break;
    case 'r':
      RecieveMessage();
          
       mySerial.println("AT+CNMI=2,2,0,0,0");
       Serial.println(" Hello3 ");   
    
      break;
  }

 if (mySerial.available()>0)
   Serial.write(mySerial.read());
}


 void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);           // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919654608033\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("SMS from GSM Module");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}


 void RecieveMessage()
{Serial.println(" Hello ");
 mySerial.println("AT+CNMI=2,2,0,0,0");
 if (mySerial.available()) {
    Serial.write(mySerial.read());
    Serial.write("hi");
     mySerial.println("AT+CNMI=2,2,0,0,0");
  }
 if ("AT+CNMI=2,2,0,0,0" !=0 )
{mySerial.println("Hello1");}
  // AT Command to receive a live SMS
  delay(1000);
 }  
