// Arduino Light Show - Patrick and Isaac

// Pin variables so you can easily change
const int RGB_RED = 11;
const int RGB_GREEN = 10;
const int RGB_BLUE = 9;
const int RED_1 = 7;
const int RED_2 = 6;
const int BUTTON = 5;

// Storing both button state in previous loop and current loop
int oldButton = 0;
int newButton = 0;

int toggle = 0;

void setup() {
  // Setting up pins
  pinMode(RGB_RED, OUTPUT);
  pinMode(RGB_GREEN, OUTPUT);
  pinMode(RGB_BLUE, OUTPUT);
  pinMode(RED_1, OUTPUT);
  pinMode(RED_2, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
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
  // buttonNew becomes the buttons state at the beginning of each loop
  newButton = digitalRead(BUTTON);

  // If button is pressed this loop and button wasn't pressed last loop
  if (buttonNew == 0 && buttonOld == 1) {
    // Toggle becomes not toggle: eg. toggling from 1 to 0
    toggle = !toggle;
  }

  if (toggle == 1) {
      // RGB LED displays random colour
      rgbDisplay(rand() % 255, rand() % 255, rand() % 255);
      flash(RED_1, 200);
      flash(RED_2, 200);
  }
  // buttonOld becomes the buttons state at the end of each loop
  oldButton = newButton;
}
