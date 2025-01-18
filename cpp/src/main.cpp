#include "01-convert-hex-to-base64.h"
#include "02-fixed-xor.h"

#include <cppcodec/base64_rfc4648.hpp>

#include <array>
#include <format>
#include <iostream>

using Subprogram = std::pair<const char*, void (*)()>;

constexpr std::array<Subprogram, 2> subprograms{
    {{"01-hex-to-b64", convertHexToBase64},
     {"02-fixed-xor", calculateFixedXor}},
};

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
