#ifndef AOCPP_DAY_1_H
#define AOCPP_DAY_1_H

/**
 * @brief given a input of two sides, each row has a list of numbers, find the
 * smallest number in each side, compare it with the other side, save the delta,
 * from there go up and do the same (smallest, second-smallest,
 * third-smallest..).
 */

#include "../utils/delimitation.hpp"
#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int get_distance_from_numbers(int num1, int num2) {
  int result = num1 - num2;
  if (result) {
    return result;
  }
  return (result * -1);
}

void write_to_buffer(int &result, int &total) { total += result; }

bool aoc_2024_day1(std::ifstream &data) {
  int total_distance = 0;

  std::for_each(
      std::istream_iterator<Delimitor<' '>>(data),
      std::istream_iterator<Delimitor<' '>>(), [&](std::string str) mutable {
        size_t str_size = str.size() / 2;
        std::string first = str.substr(0, str_size);
        // std::cout << first;
        std::string second = str.substr(str_size, '\n');
        std::cout << second;
        // int first_num = std::stoi(first);
        // int second_num = std::stoi(second);
        // auto result = get_distance_from_numbers(first_num, second_num);
        // write_to_buffer(result, total_distance);
      });
  std::cout << total_distance;
  return true;
}

#endif