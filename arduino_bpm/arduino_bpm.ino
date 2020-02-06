#include "BPMAnalyse.h"
#include "testValues.h"

BPMAnalyser bpmAnalyser(0);
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  int length2Analyse = 50;
  bpmAnalyser = BPMAnalyser(length2Analyse);
}
int counter = 0;
void loop() {
  delay(30);
  // put your main code here, to run repeatedly:
  int value =testValues[counter % (sizeof(testValues) / sizeof(int))];
  float bpm = bpmAnalyser.analyse(value);
  Serial.println(bpm);
  counter++;
}
