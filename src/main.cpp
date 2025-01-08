#include "2024/Day1.hpp"

#include "read_input.hpp"

#include <chrono>
#include <iostream>

int main() {

  auto data = read_file("input.txt");
  if (!data.is_open()) {
    std::cout << "File Error";
    return 1;
  }

  auto start = std::chrono::high_resolution_clock::now();
  /* ------ Insert Computation Here ------ */
  auto result = aoc_2024_day1(data);
  /* ------------------------------------- */
  auto stop = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = stop - start;
  std::cout << "Total Time: " << elapsed;

  return 0;
}