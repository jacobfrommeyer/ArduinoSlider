#include <Stepper.h>
#include "slider.h"

int limitSwitch1 = 2;
int limitSwitch2 = 3;
int camera = 7;

Stepper stepper(200, 12, 11, 10, 9);
Slider slider(limitSwitch1, limitSwitch2, 200, 12, 11, 10, 9);

void setup() {
  // put your setup code here, to run once:
  pinMode(limitSwitch1, INPUT_PULLUP);
  pinMode(limitSwitch2, INPUT_PULLUP);
  pinMode(camera, OUTPUT);
  digitalWrite(camera, LOW);
  
  stepper.setSpeed(10);
  Serial.begin(9600);

  slider.calcStepTime();
  Serial.write("\n",slider.frameRate);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(limitSwitch1) == 0)
  {
    Serial.print("limit switch 1 pressed\n");
  }
  if(digitalRead(limitSwitch2) == 0)
  {
    Serial.print("Limit switch 2 pressed\n");
  }

}
