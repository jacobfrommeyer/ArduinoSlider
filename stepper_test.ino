#include <Stepper.h>

int limitSwitch1 = 2;
int limitSwitch2 = 3;
int camera = 7;

Stepper stepper(200, 12, 11, 10, 9);

void setup() {
  // put your setup code here, to run once:
  pinMode(limitSwitch1, INPUT_PULLUP);
  pinMode(limitSwitch2, INPUT_PULLUP);
  pinMode(camera, OUTPUT);
  digitalWrite(camera, LOW);

  stepper.setSpeed(10);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  stepper.step(50);
  delay(500);
  stepper.step(-50);
  delay(500);
}
