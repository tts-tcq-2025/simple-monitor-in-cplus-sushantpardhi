#include <assert.h>
#include <iostream>
using namespace std;

bool isInRange(float value, float min, float max, const char* parameterName) {
  if (value < min || value > max) {
    cout << parameterName << " out of range!\n";
    return false;
  }
  return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  bool tempOk = isInRange(temperature, 0, 45, "Temperature");
  bool socOk = isInRange(soc, 20, 80, "State of Charge");
  bool chargeRateOk = isInRange(chargeRate, 0, 0.8, "Charge Rate");
  return tempOk && socOk && chargeRateOk;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
