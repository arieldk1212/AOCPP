#ifndef AOCPP_DAY_4_H
#define AOCPP_DAY_4_H

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>

// it can be backwards (SAMX), normal (XMAS), up/down, diagnol.
// everytime we search for an x we need to check all the ways to see if its
// valid.
// if we approach an x, check every option, modify the Options map, if all false
// continue, if one true - increment Res.

bool aoc_2024_day4(std::ifstream &Data) {
  int Res = 0;
  const int LINE_LEN = 140;
  std::string Stream((std::istreambuf_iterator<char>(Data)),
                     std::istreambuf_iterator<char>());
  for (int i = 0; i < Stream.size(); i++) {
    if (Stream[i] == 'X') {
      if (i + 3 != Stream.size() && Stream.substr(i, 4) == "XMAS") {
        ++Res;
      }
      if (i > 2 && Stream[i] != Stream.size() &&
          Stream.substr(i - 4, 4) == "SAMX") {
        ++Res;
      }
      if (i < LINE_LEN && Stream[i] != Stream.size() &&
          Stream[i] + LINE_LEN < Stream.size()) {
        if (Stream[i + LINE_LEN] == 'M' && Stream[i + LINE_LEN * 2] == 'A' &&
            Stream[i + LINE_LEN * 3] == 'S') {
          ++Res;
        }
      }
      if (i < Stream.size()) {
        if (Stream[i - LINE_LEN] == 'M' && Stream[i - LINE_LEN * 2] == 'A' &&
            Stream[i - LINE_LEN * 3] == 'S') {
          ++Res;
        }
      }
      if (i + LINE_LEN < Stream.size() && LINE_LEN - i > 3) {
        if (Stream[i - LINE_LEN - 1] == 'M' &&
            Stream[i - LINE_LEN - 2] == 'A' &&
            Stream[i - LINE_LEN - 3] == 'S') {
          ++Res;
        }
        if (Stream[i - LINE_LEN + 1] == 'M' &&
            Stream[i - LINE_LEN + 2] == 'A' &&
            Stream[i - LINE_LEN + 3] == 'S') {
          ++Res;
        }
      }
      if ((i + LINE_LEN * 4) + 3 < Stream.size()) {
        if (Stream[i + LINE_LEN - 1] == 'M' &&
            Stream[i + LINE_LEN - 2] == 'A' &&
            Stream[i + LINE_LEN - 3] == 'S') {
          ++Res;
        }
      }
      if ((i + LINE_LEN * 4) - 3 < Stream.size()) {
        if (Stream[i + LINE_LEN + 1] == 'M' &&
            Stream[i + LINE_LEN + 2] == 'A' &&
            Stream[i + LINE_LEN + 3] == 'S') {
          ++Res;
        }
      }
    }
  }

  std::cout << Res;
  return true;
}

#endif