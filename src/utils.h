#include <math.h>
#include <iostream>

namespace myUtils {

  struct Point2D {
	int x, y;
	Point2D() : x(0), y(0) {}
	Point2D(int x, int y) : x(x), y(y) {}
	double distance(const Point2D &b) const;
	friend bool operator==(const Point2D &lhs, const Point2D &rhs);
  };

}
