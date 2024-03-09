#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106_kbv.h>

Adafruit_SH1106_kbv display(128, 64, &Wire);
#define LCD_BEGIN()    display.begin(SSD1306_SWITCHCAPVCC, 0x3C)

// Your raw image data from image2cpp or the OLED Animation tool goes here:
// RAW IMAGE DATA START:

// RAW IMAGE DATA END.

void setup() {
  LCD_BEGIN();
  display.clearDisplay();

  //delay(2000);
  // Remove the two '/' before delay if you want a slight delay before the code actually starts displaying your image/animation after bootup. The number is in milliseconds.
}

void loop() {
  display.clearDisplay();
  display.drawBitmap(0, 0, BITMAP_ARRAY_NAME, 128, 64, WHITE); // Replace the BITMAP_ARRAY_NAME with the name of the array of the image. That is: const unsigned char --> epd_bitmap_name <-- [] PROGMEM = { ...
  display.display();
}
