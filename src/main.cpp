
#include <genetic-sudoku/Population.h>

int main () {

  Population<400, 3, 2> population{};
  int best = 0;

  int n = 0;
  while (n++ < 100000) {
    const auto fittest = population.getFittest();

    Population p{population};

    //p.addIndividual(fittest); // he can take whatever position he wants. its random anyways, idc.

    population = p;

    if (best < fittest.getFitness()) {
      best = fittest.getFitness();
      std::cout << fittest.getFitness() << std::endl;
      fittest.print();
    }
  }

  return 0;
}