
#include <genetic-sudoku/Population.h>

int main () {

  Population<400, 3, 7> population{};
  int best = 0;
  auto winner = population.getFittest();

  int n = 0;
  int limit = 10000;
  while (n++ < limit) {
    const auto fittest = population.getFittest();

    Population p{population};

    p.addIndividual(winner);

    //p.addIndividual(fittest); // he can take whatever position he wants. its random anyways, idc.

    population = p;

    if (n % 100 == 0) {
      std::cout << limit - n << ": " << fittest.getFitness() << std::endl;
    }

    if (best < fittest.getFitness()) {
      winner = fittest;
      best = fittest.getFitness();
    }
  }

  winner.print();

  return 0;
}