#ifndef AOCPP_DAY_2_H
#define AOCPP_DAY_2_H

#include <fstream>
#include <iostream>
#include <string>

bool IsValid(const std::vector<int> &Report) {
  int Direction = 0;
  bool RepState = true;
  bool SawStep = false;

  for (int i = 1; i < Report.size(); i++) {
    int Key = Report[i];
    int Prev = i - 1;
    int Delta = Key - Report[Prev];

    if (Delta == 0) {
      RepState = false;
      break;
    }
    if (std::abs(Delta) < 1 || std::abs(Delta) > 3) {
      RepState = false;
      break;
    }
    if (Direction == 0) {
      Direction = (Delta > 0 ? 1 : -1);
    } else if ((Delta > 0 && Direction == -1) || (Delta < 0 && Direction > 0)) {
      RepState = false;
      break;
    }
    SawStep = true;
  }

  return SawStep && RepState;
}

bool IsValidAgain(const std::vector<int> &Report) {
  std::vector<int> Temp(Report.size());
  auto it = Temp.begin();
  for (auto RepIt = Report.begin(); RepIt != Report.end(); ++RepIt, ++it) {
    Temp = Report;
    Temp.erase(it);
    if (IsValid(Temp)) {
      return true;
    }
  }
  return false;
}

bool aoc_2024_day2(std::ifstream &Data) {
  int safe_rep = 0;
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

    if (IsValid(CurReport) || IsValidAgain(CurReport)) {
      ++safe_rep;
    }
  }

  std::cout << safe_rep;
  return true;
}

#endif