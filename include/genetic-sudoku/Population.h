#pragma once

#include <array>

#include <genetic-sudoku/Individual.h>

template<unsigned int M, unsigned int N>
class Population {

 public:
  Population()
  {
    // print the first board just for giggles
    this->individuals[0].print();

  };

 private:
  std::array<Individual<N>, M> individuals{};
};