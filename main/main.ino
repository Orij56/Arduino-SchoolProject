// Arduino Light Show - Patrick and Isaac
#include <time.h>

// Pin variables so you can easily change
const int RGB_RED = 11;
const int RGB_GREEN = 10;
const int RGB_BLUE = 9;

const int RED_1 = 7;
const int RED_2 = 6;
const int BUTTON = 5;

int buttonstate = 0;
int counter = 0;
int r = rand() % 255, g = rand() % 255, b = rand() % 255;

void setup() {
  pinMode(RGB_RED, OUTPUT);
  pinMode(RGB_GREEN, OUTPUT);
  pinMode(RGB_BLUE, OUTPUT);
  pinMode(RED_1, OUTPUT);
  pinMode(RED_2, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  Serial.begin(9600);
  srand(time(NULL));
}

// Static flash fuction to prevent code repetition
static void flash(int pin, int wait) {
  digitalWrite(pin, 1);
  delay(wait);
  digitalWrite(pin, 0);
}

// Static function to display rgb values
static void rgbDisplay(int r, int g, int b){
  analogWrite(RGB_RED, r);
  analogWrite(RGB_GREEN, g);
  analogWrite(RGB_BLUE, b);
  
}

void loop() {
  buttonstate = digitalRead(BUTTON);
  rgbDisplay(r, g, b);
  if (buttonstate == LOW) {
      flash(RED_1, 100);
      delay(100);
      flash(RED_2, 100);
      r = rand() % 255, g = rand() % 255, b = rand() % 255;
  } else{
    counter ++;
    if (counter == 20000 ) {
      r = rand() % 255, g = rand() % 255, b = rand() % 255;
      counter = 0;
    }
  }
}
