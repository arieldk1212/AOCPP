#ifndef DELIMITATION_H
#define DELIMITATION_H

#include <istream>
#include <string>

template <char Delimiter> class Delimitor : public std::string {};

template <char Delimiter>
std::istream &operator>>(std::istream &is, Delimitor<Delimiter> &output) {
  std::getline(is, output, Delimiter);
  return is;
}

#endif