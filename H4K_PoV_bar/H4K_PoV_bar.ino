#include <Adafruit_NeoPixel.h>

#define DATA_PIN 1
#define NUM_PIXELS 8
Adafruit_NeoPixel pixel_strip = Adafruit_NeoPixel(NUM_PIXELS, DATA_PIN, NEO_GRB + NEO_KHZ800);

int buttonPin = 6;

int buttonState = 0;
int lastButtonState = 0;     // previous state of the button
int buttonPushCounter = 0;   // counter for the number of button presses
int brightness = 128;
int j;

unsigned long red = pixel_strip.Color(255, 0, 0);
unsigned long green = pixel_strip.Color(0, 255, 0);
unsigned long blue = pixel_strip.Color(0, 0, 255);
unsigned long white = pixel_strip.Color(255, 255, 255);
unsigned long lightBlue = pixel_strip.Color(0, 216, 230);

void setup() {
  pixel_strip.begin(); // This is a comment BTW.
  pixel_strip.show(); // Initialize all pixels to 'off'
  pixel_strip.setBrightness(brightness);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  startUp();
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
  if (buttonPushCounter % 2 == 0) {
         for (j=0; j < 8; j++) {
          pixel_strip.setPixelColor(j, red);
         }

          Serial.println("r");
          Serial.println(buttonPushCounter);

            pixel_strip.show();
          delay(250);
  } 

  if (buttonPushCounter % 3 == 0) {
         for (j=0; j < 8; j++) {
          pixel_strip.setPixelColor(j, green);
         }
         Serial.println("g");
         pixel_strip.show();

          delay(250);
  } 

  if (buttonPushCounter % 4 == 0) {
         for (j=0; j < 8; j++) {
          pixel_strip.setPixelColor(j, blue);
         }
          Serial.println("b");
          pixel_strip.show();
          buttonPushCounter = 1;
          delay(250);
  } 
}

void startUp() {
  pixel_strip.setPixelColor(0, red);
  pixel_strip.setPixelColor(1, red);
  pixel_strip.setPixelColor(2, red);

  pixel_strip.setPixelColor(3, white);
  pixel_strip.setPixelColor(4, white);

  pixel_strip.setPixelColor(5, lightBlue);
  pixel_strip.setPixelColor(6, lightBlue);
  pixel_strip.setPixelColor(7, lightBlue);

  pixel_strip.show();
}
