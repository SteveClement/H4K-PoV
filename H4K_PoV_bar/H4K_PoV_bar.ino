#include <Adafruit_NeoPixel.h>

#define DATA_PIN 1
#define NUM_PIXELS 8
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, DATA_PIN, NEO_GRB + NEO_KHZ800);

int buttonPin = 6;

int buttonState = 0;
int lastButtonState = 0;     // previous state of the button
int buttonPushCounter = 0;   // counter for the number of button presses
int brightness = 128;
int wait = 150;
int j;

struct Tuple {
  int last;
  int push;
};

unsigned long red = strip.Color(255, 0, 0);
unsigned long green = strip.Color(0, 255, 0);
unsigned long blue = strip.Color(0, 0, 255);
unsigned long white = strip.Color(255, 255, 255);
unsigned long lightBlue = strip.Color(0, 216, 230);
unsigned long black = strip.Color(0, 0, 0);

int serialDebug = 1;

void setup() {
  strip.begin(); // This is a comment BTW.
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(brightness);
  pinMode(buttonPin, INPUT_PULLUP);
  if (serialDebug) {
    Serial.begin(9600);
  }
  startUp();
  delay(500);
}

void loop() { // this is the main loop

  struct Tuple buttonStates = getButton(lastButtonState, buttonPushCounter);
  lastButtonState = buttonStates.last;
  buttonPushCounter = buttonStates.push;

  if (buttonPushCounter == 1) {
         for (j=0; j < 8; j++) {
           strip.setPixelColor(j, red);
         }
         if (serialDebug) {
           Serial.println("r");
         }
         strip.show();
         delay(wait);
  }
  if (buttonPushCounter == 2) {
         for (j=0; j < 8; j++) {
           strip.setPixelColor(j, green);
         }
         if (serialDebug) {
           Serial.println("g");
         }
         strip.show();
         delay(wait);
  }
  if (buttonPushCounter == 3) {
         for (j=0; j < 8; j++) {
           strip.setPixelColor(j, blue);
         }
         if (serialDebug) {
           Serial.println("b");
         }
         strip.show();
         delay(wait);
  }
  if (buttonPushCounter == 4) {
         rainbow(20);
         if (serialDebug) {
           Serial.println("rainbow");
         }
         strip.show();
         delay(wait);
  }
  if (buttonPushCounter == 5) {
         rainbowCycle(20);
         if (serialDebug) {
           Serial.println("rainbowCycle Flag");
         }
         strip.show();
         delay(wait);
  }
  if (buttonPushCounter == 6) {
         theaterChaseRainbow(50);
         if (serialDebug) {
           Serial.println("theaterChaseRainbow Flag");
         }
         strip.show();
         delay(wait);
  }
  if (buttonPushCounter == 7) {
         startUp();
         if (serialDebug) {
           Serial.println("startUp Flag");
         }
         strip.show();
         buttonPushCounter = 0;
         delay(wait);
  }
}

void startUp() {
  strip.setPixelColor(0, red);
  strip.setPixelColor(1, red);
  strip.setPixelColor(2, red);

  strip.setPixelColor(3, white);
  strip.setPixelColor(4, white);

  strip.setPixelColor(5, lightBlue);
  strip.setPixelColor(6, lightBlue);
  strip.setPixelColor(7, lightBlue);

  strip.show();
}

void dark() {
  for (j=0; j < 8; j++) {
    strip.setPixelColor(j, black);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
      struct Tuple buttonStates = getButton(lastButtonState, buttonPushCounter);
      if (buttonStates.last == 0) {
        dark();
        return;
      }
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
      struct Tuple buttonStates = getButton(lastButtonState, buttonPushCounter);
      if (buttonStates.last == 0) {
        dark();
        return;
      }

    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
          struct Tuple buttonStates = getButton(lastButtonState, buttonPushCounter);
          if (buttonStates.last == 0) {
            dark();
            return;
          }

        }
        strip.show();
       
        delay(wait);
       
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, 0);        //turn every third pixel off
          struct Tuple buttonStates = getButton(lastButtonState, buttonPushCounter);
          if (buttonStates.last == 0) {
            dark();
            return;
          }

        }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}

struct Tuple getButton(uint8_t lastButtonstate, uint8_t buttonPushCounter) {
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      buttonPushCounter++;
      if (serialDebug) {
        Serial.println("on");
        Serial.print("number of button pushes:  ");
        Serial.println(buttonPushCounter);
      }
    } 
    else {
      // if the current state is LOW then the button
      // went from on to off:
      if (serialDebug) {
        Serial.println("off"); 
      }
    }
  }
  // save the current state as the last state, 
  //for next time through the loop
  lastButtonState = buttonState;
  
  Tuple states = { lastButtonState, buttonPushCounter };
  return states;
}
