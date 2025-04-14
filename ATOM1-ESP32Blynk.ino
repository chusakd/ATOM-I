/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  ESP32, Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build mobile and web interfaces for any
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP32 chip.

  NOTE: This requires ESP32 support package:
    https://github.com/espressif/arduino-esp32

  Please be sure to select the right ESP32 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */

#define BLYNK_PRINT Serial


/* Fill in information from Blynk Device Info here */
//#define BLYNK_TEMPLATE_ID           "TMPxxxxxx"
//#define BLYNK_TEMPLATE_NAME         "Device"
//#define BLYNK_AUTH_TOKEN            "YourAuthToken"
#define BLYNK_TEMPLATE_ID "TMPL6-7VoPgXt"
#define BLYNK_TEMPLATE_NAME "ESP32WROOM"
#define BLYNK_AUTH_TOKEN "wganys45E5nKcdG8txvtBGjvK1D_lxga"

#include "DFRobot_DF2301Q.h"
#include <SPI.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SOS_2.4G";
char pass[] = "asdfghjkl";

int Valve1;
int Valve2;
int Valve3;
int Valve4;
int relay1 = 11;
int relay2 = 9;
int relay3 = 10;
int relay4 = 13;
int wPin;

DFRobot_DF2301Q_I2C DF2301Q;


BLYNK_WRITE(V0) {

int val = param.asInt();
String vStatus;
Serial.println(!val);
Valve1 = val;
if (val==1) {
    digitalWrite(relay1, HIGH);
    vStatus = "ON";
   } else { 
    digitalWrite(relay1, LOW);
    vStatus = "OFF";
  } 
  
  ValveStatus(relay1, vStatus);
}

BLYNK_WRITE(V1) {

int val = param.asInt();
String vStatus;
Serial.println(!val);
Valve2 = val;
if (val==1) {
    digitalWrite(relay2, HIGH);
    vStatus = "ON";
   } else { 
    digitalWrite(relay2, LOW);
    vStatus = "OFF";
  } 
  
  ValveStatus(relay2, vStatus);
}

BLYNK_WRITE(V2) {

int val = param.asInt();
String vStatus;
Serial.println(!val);
Valve3 = val;
if (val==1) {
    digitalWrite(relay3, HIGH);
    vStatus = "ON";
   } else { 
    digitalWrite(relay3, LOW);
    vStatus = "OFF";
  } 
  
  ValveStatus(relay3, vStatus);
}

BLYNK_WRITE(V3) {

int val = param.asInt();
String vStatus;
Serial.println(!val);
Valve4 = val;
if (val==1) {
    digitalWrite(relay4, HIGH);
    vStatus = "ON";
   } else { 
    digitalWrite(relay4, LOW);
    vStatus = "OFF";
  } 
  
  ValveStatus(relay4, vStatus);
}

void setup()
{
  // Debug console
  Serial.begin(19200);


  initRelay();
  while (!(DF2301Q.begin())) {
      Serial.println("Communication with DF230IQ failed, please check connection");
      delay(3000);
  }
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  delay(2000);
}

void loop()
{
 
  uint8_t CMDID = DF2301Q.getCMDID();
  if (CMDID != 0) {
    Serial.print("CMDID = ");  //Printing command ID
    Serial.println(CMDID);
  }

  switch (CMDID) {
    case 0:
      Serial.print("CMDID = ");  //Printing command ID
      Serial.println(CMDID);
      break;
    case 5: // Close all valve
      //Blynk.virtualWrite(V0, LOW);
      //Blynk.virtualWrite(V1, LOW);
      //Blynk.virtualWrite(V2, LOW);
      //Blynk.virtualWrite(V3, LOW);
      //Serial.println("Close all valve");
      
      Blynk.virtualWrite(V0, HIGH);
      digitalWrite(relay1, HIGH);
  
      CMDID=0;
      break;
    case 6:  // Table 1 Water On 
      
      Blynk.virtualWrite(V1, HIGH);
      digitalWrite(relay2, HIGH);
      Serial.print("Table 2 Water ");
      Serial.println(Valve1);

      CMDID=0;
      break;
    case 7:  // เปิด micrososft word
    
      Serial.println("Valve 3");
      Blynk.virtualWrite(V2, HIGH);
      digitalWrite(relay3, HIGH);
    
      CMDID=0;
      break;
    case 8:  // แสดง QR Code
//      M5.Lcd.fillScreen(BLACK);
//      M5.Lcd.qrcode("http://www.m5stack.com", 0, 0, 150, 6);

      Blynk.virtualWrite(V3, HIGH);
      digitalWrite(relay4, HIGH);
      CMDID=0;
      break;
    case 9:  // เปิด Excel
      Serial.println("Open MS Excel");
      CMDID=0;
      break;
    case 10:  // เปิด Spotify
      Serial.println("Open Spotify");
      CMDID=0;
      break;
    case 11:  // Alfred ตื่นทำงาน
      Serial.println("Wake up alfred");
      CMDID=0;
      break;
    case 12: // Close Windows
      Serial.println("Close Windows");
      CMDID=0;
      delay(500);

      break;
    case 13: //เปิด Arduino IDE 
      Serial.println("Open Arduino IDE");
      CMDID=0;
      break;
    case 14: // เปลี่ยน  Config
      Serial.println("Change Configuration");
      /* 1. What you want to change ? {$1}
            1.1 Change Response Mode. to -> text/voice {$2}
            1.2 Change PromptpayID {$2}. 
         2. Change {$1} to {$2} Done !. 
            reponse mode (text, voice), promptpayID,  
      */
      break;
    case 15: // master host
      Serial.print("Open storage master host"); 

      break;
    case 16: //ESC
      Serial.print("ESC press"); 

      break;
    case 17: //เปิด Browser
      Serial.println("Open Browser");

      break;
    case 92: // play/pause music
      Serial.print("Play music press"); 

      break;
    case 93: //stop playing
      Serial.print("Stop playing press"); 

      break;
    case 95: // The next track
      Serial.print("Next track press"); 

      break;
    case 96: // Repeat track
      Serial.print("Repeat track press"); 

      break;
    case 97: // Volume Up
      Serial.print("Volume up press"); 

      break;
    case 98: //Volume Down
      Serial.print("Volume down press"); 

      break;
    default:
      if (CMDID != 0) {
        Serial.print("CMDID = ");  //Printing command ID
        Serial.println(CMDID);
      }

      CMDID=0;
      delay(500);
      break;
  }
  
  Blynk.run();
    /**
     @brief Get the ID corresponding to the command word 
     @return Return the obtained command word ID, returning 0 means no valid ID is obtained
  */
}

void initRelay()
{

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);

  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, LOW);
}

void ValveStatus(int pTable, String pStatus)
{
  String text1; 
  
  text1 = "MCU Pin " + String(pTable) + " Status = " + pStatus;
//  digitalWrite(pTable, pEvent);  

  Serial.println(text1);
  delay(200); 

}