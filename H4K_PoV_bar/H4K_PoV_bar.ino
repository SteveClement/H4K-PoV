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
          pixel_strip.setPixelColor(0, red);
          pixel_strip.setPixelColor(1, red);
          pixel_strip.setPixelColor(2, red);
          pixel_strip.setPixelColor(3, red);
          pixel_strip.setPixelColor(4, red);
          pixel_strip.setPixelColor(5, red);
          pixel_strip.setPixelColor(6, red);
          pixel_strip.setPixelColor(7, red);

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
          pixel_strip.setPixelColor(0, blue);
          pixel_strip.setPixelColor(1, blue);
          pixel_strip.setPixelColor(2, blue);
          pixel_strip.setPixelColor(3, blue);
          pixel_strip.setPixelColor(4, blue);
          pixel_strip.setPixelColor(5, blue);
          pixel_strip.setPixelColor(6, blue);
          pixel_strip.setPixelColor(7, blue);
          Serial.println("b");
          pixel_strip.show();
          buttonPushCounter = 1;
          delay(250);
  } 


/*
  // This function is called colorWipe and takes 2 arguments, color and a wait time
      pixel_strip.setPixelColor(0, red);
      pixel_strip.setPixelColor(1, red);
      pixel_strip.setPixelColor(2, red);
      pixel_strip.setPixelColor(3, red);
      pixel_strip.setPixelColor(4, red);
      pixel_strip.setPixelColor(5, red);
      pixel_strip.setPixelColor(6, red);
      pixel_strip.show();
        if (digitalRead(buttonPin) == LOW)
  {
      pixel_strip.setPixelColor(0, green);
      pixel_strip.setPixelColor(1, green);
      pixel_strip.setPixelColor(2, green);
      pixel_strip.setPixelColor(3, green);
      pixel_strip.setPixelColor(4, green);
      pixel_strip.setPixelColor(5, green);
      pixel_strip.setPixelColor(6, green);
      pixel_strip.show();
  }
*/
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
