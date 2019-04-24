#include "tests.h"

void testUtils() {

  myUtils::Point2D p1(10, 20);
  myUtils::Point2D p2(10, 20);
  myUtils::Point2D p3(30, 40);

  assert(p1 == p2);
  assert(abs(p1.distance(p3) - 28.2843) <= EPSILON); // float testing
}

void testCharges() {
  myUtils::Point2D position(100, 20);
  myUtils::Point2D p1(15, 30);
  Charge c1(p1, 0.000000004);
  Charge c2(15, 30, 0.000000004);
  auto voltage1 = c1.calculateVoltage(position);
  auto voltage2 = c2.calculateVoltage(position);
  assert(voltage1 == voltage2);
}

void testSimulator() {
  Simulator s(10, 10, 10, 10, 5); 
  s.simulate(false);
  std::cout << "Simulation Successful\n";
}

void test() {
  std::cout << "Beginning Tests...\n\n";

  testUtils();
  testCharges();
  testSimulator();

  std::cout << "\nFinished Tests.\n\n";
}
