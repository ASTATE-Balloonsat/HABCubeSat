#include <Arduino.h>
#include "CubeSat/CubeSatInitializer.h"
#include "CubeSat/CubeSatModule.h"

CubeSatModule* module; 

// put function declarations here:
int myFunction(int, int);

void setup() {
}

void loop() {
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}