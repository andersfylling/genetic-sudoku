
#include <genetic-sudoku/Population.h>

int main () {

  Population population{};

  const auto fittest = population.getFittest();
  fittest.print();
  std::cout << fittest.getFitness() << std::endl;

  return 0;
}