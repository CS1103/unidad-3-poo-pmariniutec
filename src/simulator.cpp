#include "simulator.h"

Simulator::Simulator(int w, int h, int partitions_w, int partitions_h, int num_charges)
					: w(w), h(h), partitions_w(partitions_w), partitions_h(partitions_h) {

  srand(time(NULL));

  double q;
  myUtils::Point2D point;

  for (auto i = 0; i < num_charges; i++) {
	do {
	  point = myUtils::Point2D(rand() % w, rand() % h);
	} while(!validatePosition(point));

	q = ((double) rand() / RAND_MAX * 2.0 - 1.0) / 100000;
	Charge c = Charge(point, q);
	charges.push_back(c);
  }
}

bool Simulator::validatePosition(const myUtils::Point2D point) {

  if (charges.empty()) return true;

  auto it = std::find_if(charges.begin(), charges.end(), [point](const Charge &c) {
	return c.position == point;
  });

  if (it != charges.end()) {
	mem.push_back(it->position);
	return true;
  }

  return false;
}

void Simulator::simulate(bool print) {
  double voltage = 0;
  double step_w = w / partitions_w;
  double step_h = h / partitions_h;

  for (int i = 0; i < w; i += step_w) {
	for (int j = 0; j < h; j += step_h) {
	  voltage = getVoltageAtPoint(i, j);
	  if (print) std::cout << i << ' ' << j << ' ' << voltage << '\n';
	}
  }
}

double Simulator::getVoltageAtPoint(int x, int y) {
  double total = 0;
  myUtils::Point2D pos(x, y);
  for (const auto &charge : charges) {
    total += charge.calculateVoltage(pos);
  }
  return total;
}
