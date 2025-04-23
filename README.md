# ATOM-I
An IoT Project (ESP32-Blynk-4Relays)

Source Code LESIY[ โมดูลรีเลย์ บลูทูธ 4 ช่องทาง AC DC ESP32 WIFI ESP32-WROOM
โครงการนี้ผมได้แรงบันดาลใจมาจาก Project จบปริญญาตรีของลูกสาวที่เธอตัดสินใจทำโครงการ IoT ตามที่ผมแนะนำ (เหตุผลคือนางเรียน Commu. Eng. และผมเป็น Comp. Eng.)

หลังจากปรับปรุงและค้นคว้าอยู่ซักพักนึงผมก็ได้ Solution สำหรับควบคุมระบบไฟอัตโนมัติจนได้โดยที่ผมเลือกใช้ โมดูลรีเลย์ บลูทูธ 4 ช่องทาง AC DC ESP32 WIFI ESP32-WROOM ซึ่งมีจำหน่ายอยู่ใน Shoppee 
![image](https://github.com/user-attachments/assets/ecda0735-b25e-4675-aa0a-6e2c460572d2)

Ref: https://shopee.co.th/%E0%B9%82%E0%B8%A1%E0%B8%94%E0%B8%B9%E0%B8%A5%E0%B8%A3%E0%B8%B5%E0%B9%80%E0%B8%A5%E0%B8%A2%E0%B9%8C-%E0%B8%9A%E0%B8%A5%E0%B8%B9%E0%B8%97%E0%B8%B9%E0%B8%98-4-%E0%B8%8A%E0%B9%88%E0%B8%AD%E0%B8%87%E0%B8%97%E0%B8%B2%E0%B8%87-AC-DC-ESP32-WIFI-ESP32-WROOM-i.213822361.16962686371

เนื่องจากผมเคยลองเขียน Code ไว้แล้ว แต่ด้วยความสงสัยผมเลยเอา Code ที่มีไปให้ ChatGPT สร้าง Prompt ไว้ให้ผมใช้ในภายหลังซึ่งผมใช้หลักการ Reverse Engineering จนได้ Prompt นี้มา

"Write Arduino C code for an ESP32-WROOM-32 that connects to WiFi SSID "SOS_2.4G" with password "asdfghjkl", and uses the Blynk IoT platform.

Include the following features:

Use Blynk Template ID: "TMPL6IPn-sG-c", Template Name: "ESP32WROOMRestRoom", and Auth Token: "04ymt3OJZrgfExu8KMSj_EDRDWi-xxxx".

Control 4 relays connected to GPIO 33, 35, 32, and 34 using virtual pins V0, V1, V2, and V3 respectively.

When a relay is toggled via the Blynk app, print to the serial monitor whether it is ON or OFF, along with its GPIO pin.

Default baud rate: 19200.

All relays should be set to LOW initially in the setup() function.

Include helper functions to initialize relays and display valve status."

