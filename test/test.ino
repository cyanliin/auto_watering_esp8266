#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  Serial.begin(9600);
  u8g2.begin();
  pinMode(LED_BUILTIN, OUTPUT);  // Initialize the LED_BUILTIN pin as an output
  pinMode(A0, INPUT); 
}

// the loop function runs over and over again forever
void loop() {

  

  //digitalWrite(LED_BUILTIN, LOW);  // Turn the LED on (Note that LOW is the voltage level
  // but actually the LED is on; this is because
  // it is active low on the ESP-01)
  //delay(1000);                      // Wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH

  int sensorValue = analogRead(A0);
  Serial.print("soil value:");
  Serial.println(sensorValue);

  u8g2.clearBuffer();					// clear the internal memory
  u8g2.setFont(u8g2_font_calibration_gothic_nbp_tr);	// choose a suitable font
  char txts[5];
  snprintf(txts, 5, "%d", sensorValue);
  u8g2.drawStr(15,15, txts);	// write something to the internal memory
  u8g2.sendBuffer();

  delay(2000);                      // Wait for two seconds (to demonstrate the active low LED)
}
