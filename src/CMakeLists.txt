
project(genetic_sudoku)


# Files to be compiled.
file(GLOB genetic_sudokufiles
        main.cpp)

add_executable(genetic_sudoku ${genetic_sudokufiles})

# Make this folder linkable for parent folder.
target_link_libraries(genetic_sudoku -lpthread)