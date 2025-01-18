#include "01-convert-hex-to-base64.h"

#include <cppcodec/base64_rfc4648.hpp>

#include <array>
#include <format>
#include <iostream>

constexpr std::array<std::pair<const char*, void (*)()>, 1> subprograms{
    {{"hex_to_b64", convertHexToBase64}}};

void printUsage(char* argv[]) {
  std::cout << std::format("{} <subcommand>", argv[0]) << '\n' << '\n';
  std::cout << "Allowed subcommands:" << '\n';

  for (const auto& item : subprograms) {
    std::cout << item.first << '\n';
  }
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printUsage(argv);
    return -1;
  }

  for (const auto& item : subprograms) {
    if (std::string(argv[1]) == item.first) {
      item.second();
      return 0;
    }
  }

  std::cout << "Unknown subcommand: " << argv[1] << '\n';
  printUsage(argv);
  return -1;
}