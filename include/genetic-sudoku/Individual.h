#pragma once

// system dependencies
#include <iostream> // cout
#include <cstdint>  // uintX_t
#include <array>
#include <random>   // generating gene values

// Local dependencies
#include <genetic-sudoku/utils.h>

template<unsigned int N> // N^4 board
class Individual {

 public:
  /**
   * Constructor
   */
  Individual ()
  {
    for (uint8_t i = 0; i < N*N*N*N; i++) {
      std::random_device rd;
      std::mt19937 rng(rd());
      std::uniform_int_distribution<int> uni(0, N*N);

      this->genes[i] = static_cast<uint8_t>(uni(rng));
    }
  }

  /**
   * Constructor
   *
   * @param hints An array of all the initial hints.
   *              These are used for new boards that aren't empty,
   *              but contain at least 17 filled in squares (genes).
   * @deprecated This contructor wont be used for empty boards anyways.
   */
  Individual (const std::array<uint8_t, N*N*N*N> hints)
  {}

  /**
   * Constructor for breeding
   *
   * @param firstDonor Array of its genes. The first part of this sequence will be used.
   * @param firstDonor Array of its genes. The part after the split index of this sequence will be used.
   * @param split Index of where the genes should crossover. The new gene sequence starts after the split.
   */
  Individual (const std::array<uint8_t, N*N*N*N> firstDonor, const std::array<uint8_t, N*N*N*N> secondDonor, const uint8_t split)
  {
    // Crossover
    // Add the first gene sequence
    for (uint8_t i = 0; i < split; i++) {
      this->genes[i] = firstDonor[i];
    }
    // Add the second gene sequence
    for (uint8_t i = split; i < N*N*N*N; i++) {
      this->genes[i] = secondDonor[i];
    }

    // Mutation. TODO-Mutation: blæh
  }

  uint8_t getGene(const unsigned int index) const
  {
    return this->genes[index];
  }

  void setGene(const unsigned int index, const uint8_t gene)
  {
    this->genes[index] = gene;
  }

  int getFitness()
  {
    // TODO-fitness: find a way to calculate the fitness. higher score per possible position? bonus points?
  }

  // create a unique id for this solution, based on the genes.
  // should be used to compare to other solutions.
  int uniqueID();

  /**
   * Draws the gene sequence in the form of a sudoku board.
   */
  void print() const
  {
    std::string board = " ┏";

    // print the top hat
    for (auto i = 0; (i + 1) < N*N; i++) {
      board += (i + 1) % N == 0 ? "━━━┳" : "━━━┯";
    }
    board += "━━━┓\n";

    // for every row
    for (auto i = 0; i < N*N; i++) {
      board += " ┃ ";
      // for every column in that row
      for (auto j = 0; j < N*N; j++) {
        const uint8_t v = this->genes[i * N*N + j];
        board += v == 0 ? " " : std::to_string(v);
        board += ' ';

        // if this is the end of a subboard, print a line
        if ((j + 1) % N == 0) {
          board += "┃ ";
        }
        else {
          board += "│ ";
        }
      }


      // if this is the bottom of a subboard, print a line
      if ((i + 1) % N == 0) {
        // print the line
        board += i + 1 != N*N ? "\n ┣" : "\n ┗";
        for (auto j = 0; (j + 1) < N * N; j++) {
          if (i + 1 != N*N) {
            board += (j + 1) % N == 0 ? "━━━╋" : "━━━┿";
          }
          else {
            board += (j + 1) % N == 0 ? "━━━┻" : "━━━┷";
          }
        }
        if (i + 1 != N * N) {
          board += "━━━┫";
        } else {
          board += "━━━┛";
        }
      }
      else {
        // print the line
        board += "\n ┣";
        for (auto j = 0; (j + 1) < N*N; j++) {
          board += (j + 1) % N == 0 ? "───╂" : "───┼";
        }
        if (i + 1 != N*N) {
          board += "───┨";
        }
        else {
          board += "━━━┛";
        }
      }

      board += '\n';
    }

    // print solution
    std::cout << board << std::endl;
  }


  // Constexpr
  /**
   * Get the row for a given index.
   *
   * N^4 board layout, where N = 3.
   * 00	01 02 03 04	05 06 07 08
   * 09 10 11 12 13	14 15 16 17
   * 18	19 20 21 22	23 24 25 26
   * 27	28 29 30 31 32 33 34 35
   * 36	37 38 39 40	41 42 43 44
   * 45	46 47 48 49 50 51 52 53
   * 54	55 56 57 58	59 60 61 62
   * 63 64 65 66 67 68 69 70 71
   * 72 73 74 75 76 77 78 79 80
   *
   * @param index
   * @return
   */
  constexpr uint8_t getRow(const unsigned int index) const
  {
    return index / (N*N);
  }

  /**
   * Get the column for a given index.
   *
   * N^4 board layout, where N = 3.
   * 00	01 02 03 04	05 06 07 08
   * 09 10 11 12 13	14 15 16 17
   * 18	19 20 21 22	23 24 25 26
   * 27	28 29 30 31 32 33 34 35
   * 36	37 38 39 40	41 42 43 44
   * 45	46 47 48 49 50 51 52 53
   * 54	55 56 57 58	59 60 61 62
   * 63 64 65 66 67 68 69 70 71
   * 72 73 74 75 76 77 78 79 80
   *
   * @param index
   * @return
   */
  constexpr uint8_t getCol(const unsigned int index) const
  {
    return index % (N*N);
  }

 private:
  std::array<uint8_t, N*N*N*N> genes{};

};