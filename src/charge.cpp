#include "charge.h"
#include <iostream>

Charge::Charge(int x, int y, double q) : q(q) {
  position = myUtils::Point2D(x, y);
}

Charge::Charge(myUtils::Point2D p, double q) : position(p), q(q) {}

double Charge::calculateVoltage(myUtils::Point2D pos) const {
  return (K * q) / position.distance(pos);
}
