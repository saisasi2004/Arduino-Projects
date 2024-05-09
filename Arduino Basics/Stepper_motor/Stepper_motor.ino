#include<Stepper.h>
int stepsperrev=2048;
int motspeed=10;

Stepper mystep(stepsperrev,9,10,11,12);

void setup() {
  // put your setup code here, to run once:
mystep.setSpeed(motspeed);
}

void loop() {
  // put your main code here, to run repeatedly:
mystep.step(stepsperrev);

}
