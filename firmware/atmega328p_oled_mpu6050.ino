#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_MPU6050 mpu;

// ---------------- Pin Definitions ----------------

#define LED_PIN       13
#define BUZZER_PIN    3
#define BUTTON_PIN    2


bool alert = false;
bool sensorOK = false;

const float tiltThreshold = 3.0;

void setup() {

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  Wire.begin();

  // ---------------- OLED ----------------

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (1);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(2);
  display.setCursor(0,0);
  display.println("ATmega");

  display.setTextSize(1);
  display.println("328P Development");
  display.println("Initializing...");
  display.display();

  delay(1500);

  // ---------------- MPU6050 ----------------

  if (mpu.begin()) {
    sensorOK = true;
  }

  display.clearDisplay();

  if(sensorOK){

    display.setCursor(0,0);
    display.setTextSize(2);
    display.println("READY");

    display.setTextSize(1);
    display.println();
    display.println("MPU6050 Detected");
    display.println("OLED OK");
    display.display();

    tone(BUZZER_PIN, 2000, 150);
    delay(250);
    tone(BUZZER_PIN, 2000, 150);

  }else{

    display.setCursor(0,0);
    display.setTextSize(2);
    display.println("ERROR");

    display.setTextSize(1);
    display.println();
    display.println("MPU6050 Missing");
    display.display();

    while(1){
      digitalWrite(LED_PIN,!digitalRead(LED_PIN));
      tone(BUZZER_PIN,1000,100);
      delay(300);
    }
  }

  delay(1500);
}

void loop() {

  sensors_event_t accel, gyro, temp;

  mpu.getEvent(&accel, &gyro, &temp);

  float tilt = abs(accel.acceleration.z - 9.81);

  if(tilt > tiltThreshold){
    alert = true;
  }

  if(digitalRead(BUTTON_PIN)==LOW){
    alert = false;
  }

  digitalWrite(LED_PIN, alert);

  if(alert){
    tone(BUZZER_PIN,1500);
  }else{
    noTone(BUZZER_PIN);
  }

  display.clearDisplay();

  display.setTextSize(1);

  display.setCursor(0,0);
  display.println("ATmega328P");

  display.print("X: ");
  display.println(accel.acceleration.x,2);

  display.print("Y: ");
  display.println(accel.acceleration.y,2);

  display.print("Z: ");
  display.println(accel.acceleration.z,2);

  display.println();

  if(alert){

    display.setTextSize(2);
    display.println("ALERT");

  }else{

    display.setTextSize(2);
    display.println("NORMAL");

  }

  display.display();

  delay(200);

}
