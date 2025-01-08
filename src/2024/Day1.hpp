#ifndef AOCPP_DAY_1_H
#define AOCPP_DAY_1_H

/**
 * @brief given a input of two sides, each row has a list of numbers, find the
 * smallest number in each side, compare it with the other side, save the delta,
 * from there go up and do the same (smallest, second-smallest,
 * third-smallest..).
 */

#include <cstdint>
#include <string>
#include <vector>

decltype(auto) aoc_2024_day1(std::ifstream &data) {
  std::vector<int> vec_data;
  
  return true;
}

int get_distance_from_numbers(int num1, int num2) {
  int result = num1 - num2;
  if (result) {
    return result;
  }
  return (result * -1);
};

void write_to_buffer(int result, std::vector<int> &buffer) {
  buffer.emplace_back(result);
}


#endif