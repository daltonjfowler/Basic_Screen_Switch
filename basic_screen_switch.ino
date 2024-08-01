#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

int buttonPin = 2;  //button in D2
int screen = 0;     //hold which screen is being selected


//U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);  // High speed I2C

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/SCL, /* data=*/SDA, /* reset=*/U8X8_PIN_NONE);  //Low spped I2C

void setup(void) {
  u8g2.begin();
}

void loop(void) {
  if (digitalRead(buttonPin == 1)) {
    if (screen == 0)  //change what screen we will display
    {
      screen = 1;
    } else {
      screen = 0;
    }
    u8g2.clearBuffer();
    delay(250);
  }

  if (screen == 0) {
    u8g2.clearBuffer();                  // clear the internal memory
    u8g2.setFont(u8g2_font_ncenB08_tr);  // choose a suitable font
    u8g2.drawStr(0, 10, "Screen 0!");    // write something to the internal memory
    u8g2.sendBuffer();                   // transfer internal memory to the display
    delay(1000);
  }
  if (screen == 1) {
    u8g2.clearBuffer();                  // clear the internal memory
    u8g2.setFont(u8g2_font_ncenB08_tr);  // choose a suitable font
    u8g2.drawStr(0, 10, "Screen 1!");    // write something to the internal memory
    u8g2.sendBuffer();                   // transfer internal memory to the display
    delay(1000);
  }
}