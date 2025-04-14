
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6l_VoJ4cP"
#define BLYNK_TEMPLATE_NAME "SOS Organic Farm"
#define BLYNK_AUTH_TOKEN "NRcwWFNG-Wqs31rk6uahlTFLweviiwHB"

#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
#include <SPI.h>
#include <WiFiS3.h>
#include <BlynkSimpleWifi.h>



ArduinoLEDMatrix matrix;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SOS_2.4G"; //ใส่ชื่อ WiFi ที่ต้องการให้บอร์ดเชื่อมต่อ โดยต้องเป็น 2G เท่านั้น
char pass[] = "asdfghjkl"; //ใส่รหัส WiFi

int Valve1 = 2;
int Valve2 = 3;
int Valve3 = 4;
int Valve4 = 5;
int Valve5 = 8;
int Valve6 = 9;
int Valve7 = 10;
int Valve8 = 11;
int wPin;

BLYNK_WRITE(V0) {

int val = param.asInt();
String vStatus;
Serial.println(!val);

if (val==1) {
    digitalWrite(Valve1, HIGH);
    vStatus = "ON";
   } else { 
    digitalWrite(Valve1, LOW);
    vStatus = "OFF";
  } 
  
  WaterSupply(Valve1, vStatus);
}

BLYNK_WRITE(V1) {
  int val = param.asInt();
  String vStatus;
  Serial.println(val);

  if (val==1)
  {
    digitalWrite(Valve2, HIGH);
    vStatus = "ON";
  } else { 
    digitalWrite(Valve2, LOW);
    vStatus = "OFF";
  } 
  
  WaterSupply(Valve2, vStatus);
}


BLYNK_WRITE(V2) {
  int val = param.asInt();
  String vStatus;

  if (val==1)
  {
    digitalWrite(Valve3, HIGH);
    vStatus = "ON";
  } else { 
    digitalWrite(Valve3, LOW);
    vStatus = "OFF";
  } 
  
  WaterSupply(Valve3, vStatus);
}

BLYNK_WRITE(V3) {
  int val = param.asInt();
  String vStatus;
  if (val==1)
  {
    digitalWrite(Valve4, HIGH);
    vStatus = "ON";
  } else { 
    digitalWrite(Valve4, LOW);
    vStatus = "OFF";
  } 
  
  WaterSupply(Valve4, vStatus);
}

BLYNK_WRITE(V4) {
  int val = param.asInt();
  String vStatus;
  if (val==1)
  {
    digitalWrite(Valve5, HIGH);
    vStatus = "ON";
  } else { 
    digitalWrite(Valve5, LOW);
    vStatus = "OFF";
  } 
  
  WaterSupply(Valve5, vStatus);
}

BLYNK_WRITE(V5) {
  int val = param.asInt();
  String vStatus;
  if (val==1)
  {
    digitalWrite(Valve6, HIGH);
    vStatus = "ON";
  } else { 
    digitalWrite(Valve6, LOW);
    vStatus = "OFF";
  } 
  
  WaterSupply(Valve6, vStatus);
}

BLYNK_WRITE(V6) {
  int val = param.asInt();
  String vStatus;
  if (val==1)
  {
    digitalWrite(Valve7, HIGH);
    vStatus = "ON";
  } else { 
    digitalWrite(Valve7, LOW);
    vStatus = "OFF";
  } 
  
  WaterSupply(Valve7, vStatus);
}

BLYNK_WRITE(V7) {
  int val = param.asInt();
  String vStatus;
  if (val==1)
  {
    digitalWrite(Valve8, HIGH);
    vStatus = "ON";
  } else { 
    digitalWrite(Valve8, LOW);
    vStatus = "OFF";
  } 
  
  WaterSupply(Valve8, vStatus);
}

void setup()
{
  pinMode(Valve1, OUTPUT);
  pinMode(Valve2, OUTPUT);
  pinMode(Valve3, OUTPUT);
  pinMode(Valve4, OUTPUT);
  pinMode(Valve5, OUTPUT);
  pinMode(Valve6, OUTPUT);
  pinMode(Valve7, OUTPUT);
  pinMode(Valve8, OUTPUT);
  // Debug console
  Serial.begin(19200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  matrix.begin();
  matrix.beginDraw();
  matrix.stroke(0xFFFFFFFF);
  matrix.textScrollSpeed(100);
  const char text[] = " ATOM R1 ";
  matrix.textFont(Font_4x6);
  matrix.beginText(0, 1, 0xFFFFFF);
  matrix.println(text);
  matrix.endText(SCROLL_LEFT);
  matrix.endDraw();
  initRelay();
  delay(2000);
}

void loop()
{
  Blynk.run();
  //displayWorkingPin(); 
  

}

void displayWorkingPin()
{
  
  const char text[] = "  Son of the Sun   ";

  matrix.beginDraw();
  matrix.stroke(0xFFFFFFFF);
  matrix.textScrollSpeed(50);
  matrix.textFont(Font_5x7);
  matrix.beginText(0, 1, 0xFFFFFF);
  matrix.println(text);
  matrix.endText(SCROLL_LEFT);
  matrix.endDraw();
  delay(2000);
}

void WaterSupply(int pTable, String pStatus)
{
  String text1; 
  
  text1 = "Table " + String(pTable-1) + " Status = " + pStatus;
//  digitalWrite(pTable, pEvent);  

  Serial.println(text1);
  delay(200); 

}

void initRelay()
{
  digitalWrite(Valve1, LOW);
  digitalWrite(Valve2, LOW);
  digitalWrite(Valve3, LOW);
  digitalWrite(Valve4, LOW);
  digitalWrite(Valve5, LOW);
  digitalWrite(Valve6, LOW);
  digitalWrite(Valve7, LOW);
  digitalWrite(Valve8, LOW);
}

