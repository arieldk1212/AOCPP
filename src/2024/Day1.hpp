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
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>

int get_distance_from_numbers(int num1, int num2) {
  return std::abs(num1 - num2);
  auto x = std::function<void(int)>();
}

void write_to_buffer(int &result, int &total) { total += result; }

bool aoc_2024_day1(std::ifstream &data) {
  int total_distance = 0;

  // std::for_each(std::istream_iterator<Delimitor<'\n'>>(data),
  //               std::istream_iterator<Delimitor<'\n'>>(),
  //               [&](const std::string str) mutable {
  //                 if (!str.empty()) {
  //                   std::istringstream str_stream(str);
  //                   int left, right;
  //                   str_stream >> left >> right;
  //                   if (str_stream) {
  //                     auto result = get_distance_from_numbers(left, right);
  //                     write_to_buffer(result, total_distance);
  //                   }
  //                 }
  //               });
  // std::cout << total_distance;

  std::unordered_map<int, uint32_t> left, right;
  std::for_each(
      std::istream_iterator<std::string>(data),
      std::istream_iterator<std::string>(),
      [next_cont = &left, prev_cont = &right](std::string str) mutable {
        ++(*next_cont)[str.size()];
        std::swap(next_cont, prev_cont);
      });

  size_t score = 0;
  for (auto [n, times] : left) {
    score += n * times * (right.contains(n) ? right[n] : 0);
  }

  std::cout << score << std::endl;
  return true;
}

#endif