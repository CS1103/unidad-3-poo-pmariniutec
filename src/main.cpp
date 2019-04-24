#include <iostream>

#include "simulator.h"
#include "../tests/tests.h"

#define TEST 1

int main() {

#if TEST == 1
  test();
#endif

  std::cout << "Starting Program...\n";

  Simulator s(10, 10, 10, 10, 5); 
  s.simulate(true);
}

