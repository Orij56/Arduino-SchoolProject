// Arduino Light Show - Patrick and Isaac

// Pin variables so you can easily change
static int RGB_RED = 6;
static int RGB_BLUE = 11;
static int RGB_GREEN = 10;
int joe = 0;
static int RED_1 = 9;
static int RED_2 = 8;

static int SPEAKER = 7;


void setup() {
  pinMode(RGB_RED, OUTPUT);
  pinMode(RGB_GREEN, OUTPUT);
  pinMode(RGB_BLUE, OUTPUT);
  pinMode(RED_1, OUTPUT);
  pinMode(RED_2, OUTPUT);
  pinMode(SPEAKER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(RGB_RED, joe);
  joe = joe + 1;
  if (joe>255) {
    joe = 0;
  }
  Serial.write(joe);
  analogWrite(RGB_BLUE, 0);
  analogWrite(RGB_GREEN, 0);
}
