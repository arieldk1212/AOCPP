#ifndef AOCPP_DAY_2_H
#define AOCPP_DAY_2_H

#include <fstream>
#include <iostream>
#include <string>

bool aoc_2024_day2(std::ifstream &Data) {
  int safe_rep = 0;
  int fixable_rep = 0;
  std::string Stream;

  while (std::getline(Data, Stream)) {
    std::string CurNum;
    std::vector<int> CurReport;

    for (const auto &c : Stream) {
      if (c == ' ') {
        if (!CurNum.empty()) {
          CurReport.push_back(std::stoi(CurNum));
          CurNum.clear();
        }
      }
      CurNum += c;
    }
    CurReport.push_back(std::stoi(CurNum));

    int Direction = 0;
    bool RepState = true;
    bool SawStep = false;
    int IncorrectLevels = 0;
    bool ValidTurn = true;

    for (int i = 1; i < CurReport.size(); i++) {
      int MaxDelta = 0;
      int Key = CurReport[i];
      int Prev = i - 1;
      int Delta = Key - CurReport[Prev];
      if (Delta == 0) {
        RepState = false;
        ++IncorrectLevels;
      }
      if (std::abs(Delta) < 1 || std::abs(Delta) > 3) {
        RepState = false;
        ++IncorrectLevels;
      }
      if (Direction == 0) {
        Direction = (Delta > 0 ? 1 : -1);
      } else if ((Delta > 0 && Direction == -1) ||
                 (Delta < 0 && Direction > 0)) {
        RepState = false;
        ++IncorrectLevels;
      }
      MaxDelta = std::max(MaxDelta, Delta);
      if (MaxDelta >= 4) {
        ValidTurn = false;
      }
      SawStep = true;
    }
    if (ValidTurn && IncorrectLevels == 1) {
      ++fixable_rep;
      ValidTurn = true;
    }

    if (RepState && SawStep) {
      ++safe_rep;
    }
  }

  std::cout << safe_rep + fixable_rep;
  return true;
}

#endif