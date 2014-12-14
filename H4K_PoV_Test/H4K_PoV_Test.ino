#include <Adafruit_NeoPixel.h>

// DATA_PIN is a constant (you do not want to change your pin setup mid-program)
#define DATA_PIN 12

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

Adafruit_NeoPixel pixel_strip = Adafruit_NeoPixel(12, DATA_PIN, NEO_GRB + NEO_KHZ800);

int buttonPin = 6;
int buttonState = 0;
int lastButtonState = 0;     // previous state of the button

void setup() {
  pixel_strip.begin(); // This is a comment BTW.
  pixel_strip.show(); // Initialize all pixels to 'off'
  pixel_strip.setBrightness(32);
  pinMode(buttonPin, INPUT_PULLUP);  
}

void loop() { // this is the main loop
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
    } 
    else {
      // if the current state is LOW then the button
      // went from on to off:
      Serial.println("off"); 
    }
  }
  // save the current state as the last state, 
  //for next time through the loop
  lastButtonState = buttonState;

  
  // turns on the LED every four button pushes by 
  // checking the modulo of the button push counter.
  // the modulo function gives you the remainder of 
  // the division of two numbers:
  if (buttonPushCounter % 4 == 0) {
//    digitalWrite(ledPin, HIGH);
  } else {
//   digitalWrite(ledPin, LOW);
  }


  // This function is called colorWipe and takes 2 arguments, color and a wait time
      pixel_strip.setPixelColor(0, pixel_strip.Color(255, 0, 0));
      pixel_strip.setPixelColor(1, pixel_strip.Color(255, 0, 0));
      pixel_strip.setPixelColor(2, pixel_strip.Color(255, 0, 0));
      pixel_strip.setPixelColor(3, pixel_strip.Color(255, 0, 0));
      pixel_strip.setPixelColor(4, pixel_strip.Color(255, 0, 0));
      pixel_strip.setPixelColor(5, pixel_strip.Color(255, 0, 0));
      pixel_strip.setPixelColor(6, pixel_strip.Color(255, 0, 0));
      pixel_strip.show();
        if (digitalRead(buttonPin) == LOW)
  {
      pixel_strip.setPixelColor(0, pixel_strip.Color(0, 255, 0));
      pixel_strip.setPixelColor(1, pixel_strip.Color(0, 255, 0));
      pixel_strip.setPixelColor(2, pixel_strip.Color(0, 255, 0));
      pixel_strip.setPixelColor(3, pixel_strip.Color(0, 255, 0));
      pixel_strip.setPixelColor(4, pixel_strip.Color(0, 255, 0));
      pixel_strip.setPixelColor(5, pixel_strip.Color(0, 255, 0));
      pixel_strip.setPixelColor(6, pixel_strip.Color(0, 255, 0));
      pixel_strip.show();
  }

}

/* 
// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {

  for (uint16_t j=0; j<13; j++) {
      pixel_strip.setPixelColor(0, c);
      pixel_strip.setPixelColor(1, c);   
      pixel_strip.setPixelColor(2, c);
      pixel_strip.setPixelColor(3, c);   
      pixel_strip.setPixelColor(4, c);
      pixel_strip.setPixelColor(5, c);   
      delay(250);
      pixel_strip.setPixelColor(6, c);
      pixel_strip.setPixelColor(7, c);   
      pixel_strip.setPixelColor(8, c);
      pixel_strip.setPixelColor(9, c);   
      pixel_strip.setPixelColor(10, c);
      pixel_strip.setPixelColor(11, c);   
      pixel_strip.show();
  }
    delay(500);

for (uint16_t j=0; j<13; j++) {
    pixel_strip.setPixelColor(j, 0,255,0);
    pixel_strip.show();
}
delay(1500);
for (uint16_t j=0; j<13; j++) {
    pixel_strip.setPixelColor(j, 0);
    pixel_strip.show();
}
delay(750);
for (uint16_t j=0; j<13; j++) {
    pixel_strip.setPixelColor(j, 0,255,0);
    pixel_strip.show();
}
delay(750);
for (uint16_t j=0; j<13; j++) {
    pixel_strip.setPixelColor(j, 0);
    pixel_strip.show();
}
delay(750);
for (uint16_t j=0; j<13; j++) {
    pixel_strip.setPixelColor(j, 0,255,0);
    pixel_strip.show();
}
delay(750);
for (uint16_t j=0; j<13; j++) {
    pixel_strip.setPixelColor(j, 0);
    pixel_strip.show();
}
delay(750);
for (uint16_t j=0; j<13; j++) {
    pixel_strip.setPixelColor(j, 0,255,0);
    pixel_strip.show();
}
delay(750);
for (uint16_t j=0; j<13; j++) {
    pixel_strip.setPixelColor(j, 0);
    pixel_strip.show();
}

for (uint16_t j=0; j<13; j++) {
    pixel_strip.setPixelColor(j, 0,0,255);
    pixel_strip.show();
    delay(100);
    pixel_strip.setPixelColor(j, 0);
    pixel_strip.show();
}
*/
