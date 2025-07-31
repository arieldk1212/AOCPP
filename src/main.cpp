#include "2024/Day1.hpp"

#include <chrono>
#include <iostream>

int main() {

  static std::ifstream Data{"../input.txt"};

  if (!Data.is_open()) {
    std::cout << "File Error";
    return 1;
  }

  auto start = std::chrono::high_resolution_clock::now();
  /* ------ Insert Computation Here ------ */

  aoc_2024_day1(Data);

  Data.close();
  std::cout << "\n";
  /* ------------------------------------- */
  auto stop = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = stop - start;
  std::cout << "Total Time: " << elapsed;

  return 0;
}