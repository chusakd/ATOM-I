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
//camping area
//#define BLYNK_TEMPLATE_ID   "TMPL6-7VoPgXt"
//#define BLYNK_TEMPLATE_NAME "ESP32WROOM"
//#define BLYNK_AUTH_TOKEN    "wganys45E5nKcdG8txvtBGjvK1D_lxga"
// Tamarine Tree
//#define BLYNK_TEMPLATE_ID "TMPL6xgDHigEI"
//#define BLYNK_TEMPLATE_NAME "ESP32Tamarine2"
//#define BLYNK_AUTH_TOKEN    "Cd4Qy6SoLyUM0mo7rVOX89qpe6LFUNKn"


#define BLYNK_TEMPLATE_ID "TMPL6IPn-sG-c"
#define BLYNK_TEMPLATE_NAME "ESP32WROOMRestRoom"
#define BLYNK_AUTH_TOKEN "04ymt3OJZrgfExu8KMSj_EDRDWi-Lt1d"

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
int relay1 = 33;
int relay2 = 35;
int relay3 = 32;
int relay4 = 34;
int wPin;



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
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  delay(2000);
}

void loop()
{
 
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
