#pragma once

#include "utils.h"

static constexpr double K = 8990000000;

struct Charge {
  Charge(int x, int y, double q);
  Charge(myUtils::Point2D p, double q);
  double calculateVoltage(myUtils::Point2D pos) const;
  myUtils::Point2D position;
  double q;
};
