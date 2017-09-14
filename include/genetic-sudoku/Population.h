#pragma once

#include <array>

#include <genetic-sudoku/Individual.h>

template<unsigned int M = 256, unsigned int N = 3, unsigned int R = 17>
class Population {

 public:
  Population()
  {
    // print the first board just for giggles
    //this->individuals[0].print();

  };

  /**
   * Find the fittest individual
   * @return
   */
  Individual<N, R> getFittest() const
  {
    Individual<N, R> fittest = this->getIndividual(0);

    for (auto i = 1; i < N*N*N*N; i++) {
      if (fittest.getFitness() < this->getIndividual(i).getFitness()) {
        fittest = this->getIndividual(i);
      }
    }

    return fittest;
  }

  Individual<N, R> getIndividual (const unsigned int index) const
  {
    return this->individuals[index];
  }

 private:
  std::array<Individual<N, R>, M> individuals{};
};