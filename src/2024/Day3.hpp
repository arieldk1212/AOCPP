#ifndef AOCPP_DAY_3_H
#define AOCPP_DAY_3_H

#include <cctype>
#include <fstream>
#include <iostream>
#include <optional>
#include <string>

// sliding window, make sure not more than 1 - 3 digits.
// valid -> mul(123,123).

// std::optional<int> CheckParen(const std::string &Paren) {
//   std::pair<int, int> Nums;

//   if (std::count(Paren.begin(), Paren.end(), ',') != 1) {
//     return std::nullopt;
//   }

//   for (int r = 0; r < Paren.size(); ++r) {
//     if (Paren[r] != ',' && !std::isdigit(Paren[r])) {
//       return std::nullopt;
//     }
//   }
//   auto pos = Paren.find(',');
//   try {
//     Nums.first = std::stoi(Paren.substr(0, pos));
//     Nums.second = std::stoi(Paren.substr(pos + 1));
//   } catch (...) {
//     return std::nullopt;
//   }

//   if (Nums.first > 999 || Nums.second > 999) {
//     return std::nullopt;
//   }

//   return Nums.first * Nums.second;
// }

bool aoc_2024_day3(std::ifstream &Data) {
  std::string Stream;
  std::string FullData;
  long long OpSum = 0;

  auto GetNumber = [&](int &r) {
    int x = 0;
    while (r < Stream.size() && x < 1000 && std::isdigit(Stream[r])) {
      x = 10 * x + (Stream[r] - '0');
      r++;
    }
    if (1 <= x && x <= 999) {
      return x;
    }
    return -1;
  };

  while (std::getline(Data, FullData)) {
    Stream += FullData;
  }

  bool IsEnabled = true;

  for (int r = 0; r < Stream.size(); ++r) {
    if (r + 3 < Stream.size() && Stream.substr(r, 4) == "do()") {
      IsEnabled = true;
      continue;
    }
    if (r + 6 < Stream.size() && Stream.substr(r, 7) == "don't()") {
      IsEnabled = false;
      continue;
    }

    if (IsEnabled && Stream[r] == 'm') {
      if (Stream[r + 1] == 'u' && Stream[r + 2] == 'l' &&
          Stream[r + 3] == '(') {
        r += 4;
        int x = GetNumber(r);
        if (Stream[r] == ',') {
          r++;
          int y = GetNumber(r);
          if (Stream[r] == ')') {
            if (x != -1 && y != -1) {
              OpSum += x * y;
            }
          }
        }
      }
    }
  }

  std::cout << OpSum;
  return true;
}

#endif