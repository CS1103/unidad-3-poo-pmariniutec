#include "utils.h"
#include <iostream>

namespace myUtils {

  double Point2D::distance(const Point2D &b) const {
	return sqrt(pow(b.x - x, 2) + pow(b.y - y, 2));	
  }

  bool operator==(const Point2D &lhs, const Point2D &rhs) {
	return lhs.x == rhs.x && lhs.y == rhs.y;
  }

}
