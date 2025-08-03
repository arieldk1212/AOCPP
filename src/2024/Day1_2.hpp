#ifndef AOCPP_DAY_2_H
#define AOCPP_DAY_2_H

#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>

// 1. we need to iterate each side and check how many times a number appears
// on the different side ->
// 2. multiply that number by the number of
// apperences
// 3. add it to the total score.

bool aoc_2024_day1_2(std::ifstream &data) {
  long long sim_score = 0;
  std::string Stream;
  std::vector<uint32_t> rightv;
  std::unordered_map<uint32_t, int> leftap; // the num, num of apperences.

  while (std::getline(data, Stream)) {
    leftap[(std::stoi(Stream.substr(0, 5)))] = 0;
    rightv.push_back(std::stoi(Stream.substr(8, 5)));
  }

  for (int i = 0; i < rightv.size(); i++) {
    if (leftap.contains(rightv[i])) {
      leftap[rightv[i]]++;
    }
  }

  for (const auto &[key, value] : leftap) {
    sim_score += key * value;
  }
  std::cout << sim_score;
  return true;
}

#endif