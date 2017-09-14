#pragma once

#include <array>

#include <genetic-sudoku/Individual.h>

template<unsigned int M = 256, unsigned int N = 3, unsigned int R = 17>
class Population {

 public:
  Population()
  {};
  Population(const Population<M, N, R>& p)
  {
    Individual<N, R> fittest = p.getIndividual(0);

    for (auto i = 0; i < M; i++) {
      if (fittest.getFitness() < 0 || fittest.getFitness() < this->getIndividual(i).getFitness()) {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> uni(1, N * N * N * N - 1);

        int split = uni(rng);

        Individual<N, R>
            ind{p.getIndividual(i).getGeneSequence(), fittest.getGeneSequence(), split};
        this->individuals[i] = ind;

        fittest = p.getIndividual(i);
      }
    }
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

  void addIndividual (const Individual<N, R> i)
  {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(0, M);

    int index = static_cast<uint8_t>(uni(rng));

    this->individuals[index] = i;
  }

  void addIndividual (const Individual<N, R> i, const unsigned int index)
  {
    this->individuals[index] = i;
  }

 private:
  std::array<Individual<N, R>, M> individuals{};
};