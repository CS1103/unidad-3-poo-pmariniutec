#pragma once

#include <algorithm>
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include "charge.h"

class Simulator {
  public:
	Simulator(int w, int h, int partitions_w, int partitions_h, int num_charges);
	void simulate(bool print);

  private:
	double getVoltageAtPoint(int x, int y);
	bool validatePosition(const myUtils::Point2D point);
	int w, h;
	int partitions_w, partitions_h;
	std::vector<Charge> charges;
	std::vector<myUtils::Point2D> mem;
};
