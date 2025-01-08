#ifndef READ_INPUT_H
#define READ_INPUT_H

#include <filesystem>
#include <fstream>

static std::ifstream read_file(const std::filesystem::path &path) {
  std::ifstream Path {path};
  return Path;
};

#endif