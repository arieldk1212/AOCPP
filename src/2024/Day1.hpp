#ifndef AOCPP_DAY_1_H
#define AOCPP_DAY_1_H

/**
 * @brief given a input of two sides, each row has a list of numbers, find the
 * smallest number in each side, compare it with the other side, save the delta,
 * from there go up and do the same (smallest, second-smallest,
 * third-smallest..).
 */

#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int get_distance_from_numbers(int num1, int num2) {
  return std::abs(num1 - num2);
}

bool aoc_2024_day1(std::ifstream &data) {
  std::string stream;
  std::size_t score = 0;
  std::vector<uint32_t> leftv, rightv;

  while (std::getline(data, stream)) {
    leftv.push_back(std::stoi(stream.substr(0, 5)));
    rightv.push_back(std::stoi(stream.substr(8, 5)));
  }

  /* now we need to sort right, left */
  for (int i = 1; i < rightv.size(); ++i) {
    auto Key = rightv[i];
    auto Prev = i - 1;
    while (Prev >= 0 && Key < rightv[Prev]) {
      rightv[Prev + 1] = rightv[Prev];
      Prev--;
    }
    rightv[Prev + 1] = Key;
  }

  for (int i = 1; i < leftv.size(); ++i) {
    auto Key = leftv[i];
    auto Prev = i - 1;
    while (Prev >= 0 && Key < leftv[Prev]) {
      leftv[Prev + 1] = leftv[Prev];
      Prev--;
    }
    leftv[Prev + 1] = Key;
  }

  for (int i = 0; i < leftv.size(); i++) {
    int curleft = static_cast<int>(leftv[i]);
    int curright = static_cast<int>(rightv[i]);
    score += get_distance_from_numbers(curleft, curright);
  }

  std::cout << score;

  return true;
}

#endif