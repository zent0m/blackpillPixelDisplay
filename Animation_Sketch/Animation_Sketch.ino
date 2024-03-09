#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106_kbv.h>

Adafruit_SH1106_kbv display(128, 64, &Wire);
#define LCD_BEGIN()    display.begin(SSD1306_SWITCHCAPVCC, 0x3C)

// Your raw animation frame data from image2cpp or the OLED Animation tool goes here:
// RAW ANIMATION FRAME DATA START (next line):

// RAW ANIMATION FRAME DATA END.

void setup() {
  LCD_BEGIN();
  display.clearDisplay();

  //delay(2000);
  // Remove the two '/' before delay if you want a slight delay before the code actually starts displaying your image/animation after the device boots up. The number is in milliseconds.
}

void loop() {
  display.clearDisplay();
  display.drawBitmap(0, 0, BITMAP_ARRAY_NAME, 128, 64, WHITE); // Replace the BITMAP_ARRAY_NAME with the name of the array of the respective frame. That is: const unsigned char --> bitmapNameframe_00_delay_0 <-- [] PROGMEM = { ...
  display.display();
  // Delay after each frame is something native to GIF files. This is the delay after each frame of the GIF to give the animation a better feel.
  // In GIFs, this value is in 1/100 seconds, but over here, we need it to be in milliseconds, so we can multiply the value of the GIF delay (if the GIF has any) by 10.
  // I have put it at 0 by default, but that doesn't look very good, unless you have a high framerate animation. You can change it to anything you want.
  // You can remove these comments (lines of text that have // before them) if you're going to add in multiple frames, since it'll become an eyesore if you have tens or hundreds of frames.
  delay(0);
}
