#include <SPI.h> //library serial parallel interface
#include <Wire.h> //library untuk wire i2c
#include <RFID.h> //library RFID
#include <LiquidCrystal_I2C.h> //library LCD+I2C

LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize LCD Display at address 0x27 / 0X3F

#define sda 10 //Pin Serialdata (SDA)
#define rst 9 //pin Reset

RFID rfid(sda, rst);

void setup() {
  Serial.begin(9600); //baud komunikasi serial monitor
  lcd.begin();
  lcd.setBacklight(255); //menghidupkan lampu latar LCD
  SPI.begin(); //Prosedur antarmuka SPI
  rfid.init(); //Memulai inialisasi module RFID

  lcd.setCursor (0, 0);
  lcd.print("***RFID RC522***");
  lcd.setCursor (0, 1);
  lcd.print("  -LAWLAW ELC-  ");
  delay (5000);
  lcd.clear();
}

void loop() {
  lcd.setCursor (0, 0);
  lcd.print(" -yuk Scan RFID-");
  lcd.setCursor (0, 1);
  lcd.print("Catat IDnya!");
  
  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      lcd.clear();
      lcd.setCursor (0, 0);
      lcd.print("ID terbaca :    ");

      lcd.setCursor (0, 1);
      Serial.print(rfid.serNum[0]); //serial no.1
      Serial.print(" ");
      lcd.print(rfid.serNum[0]);

      Serial.print(rfid.serNum[1]); //serial no.2
      Serial.print(" ");
      lcd.print(rfid.serNum[1]);

      Serial.print(rfid.serNum[2]); //serial no.3
      Serial.print(" ");
      lcd.print(rfid.serNum[2]);

      Serial.print(rfid.serNum[3]); //serial no.4
      Serial.print(" ");
      lcd.print(rfid.serNum[3]);

      Serial.print(rfid.serNum[4]); //serial no.5
      Serial.println("");
      lcd.print(rfid.serNum[4]);

      delay(10000);
      lcd.clear();
    }
  }
}
