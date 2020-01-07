/*
 * Name:      Etched-Glass-Plaque
 * Purpose:   Under lighting for etched glass
 * By:        Michael Vieau/Kevin Bong (The Mayhem Lab)
 * Date       2019.06.23
 * Modified:  2019.12.23
 * Rev Level  1.0
 */

 #include <Adafruit_NeoPixel.h>

// Digispark (Attiny85)
#define LEDPIN 0
#define NUMPIXELS 100

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, LEDPIN, NEO_GRB + NEO_KHZ800);

// Global variables
int BRIGHTNESS = 100;
int COLORS = 2;
int R,G,B;
int LBUTPIN = 1;
int RBUTPIN = 2;

void setup() {
  
  pinMode(LBUTPIN,INPUT_PULLUP); // Left Button on PO
  pinMode(RBUTPIN, INPUT_PULLUP); // Right button on P2
  
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  color(255, 255, 255);
  strip.show();
  
}

void loop() {

  ButtonPress();
  delay(100);
  
}
void ButtonPress()
{
  // Check to see if a button was pushed or sleep
  if (digitalRead(LBUTPIN) == 0)
  {
    brightness();
  }
  
  if (digitalRead(RBUTPIN) == 0)
  {
    colorselect();
  }
}
// ----------------------------
void colorselect()
{
  switch (COLORS)
  {
    case 1:
      // White
      color(255, 255, 255);
      break;
    case 2:
      // Yellow
      color(255, 200, 20);
      strip.show();
      break;
    case 3:
      // Green
      color(0, 255, 0);
      strip.show();
      break;
    case 4:
      // Blue
      color(0, 0, 255);
      strip.show();
      break;
    case 5:
      // Red
      color(255, 0, 0);
      break;
    case 6:
      // Black
      color(0, 0, 0);
      break;
  }
  
  COLORS += 1;
  if (COLORS >=7)
  {
    COLORS = 1;
  }
}
// ----------------------------
void color(int R, int G, int B) {
  
  for (int i=0; i <= NUMPIXELS; i++){
    strip.setPixelColor(i, R, G, B);
  }
  strip.show();
  delay(1000);
}
// ----------------------------
void brightness() {

  BRIGHTNESS += 75;
  
  if (BRIGHTNESS >= 251)
  {
    BRIGHTNESS = 50;
  }
  
  strip.setBrightness(BRIGHTNESS);
  strip.show();
  delay(1000);
}
