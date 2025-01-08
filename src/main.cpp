#include "2024/Day1.hpp"

#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>

int main() {

  std::filesystem::path Path{"../input.txt"};
  std::ifstream Data{Path};

  if (!Data.is_open()) {
    std::cout << "File Error";
    return 1;
  }

  auto start = std::chrono::high_resolution_clock::now();
  /* ------ Insert Computation Here ------ */
  auto result = aoc_2024_day1(Data);
  /* ------------------------------------- */
  auto stop = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = stop - start;
  std::cout << "Total Time: " << elapsed;

  return 0;
}