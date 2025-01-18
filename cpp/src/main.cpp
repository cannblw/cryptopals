#include <array>
#include <format>
#include <functional>
#include <iostream>

using CommandFunction = void (*)();

constexpr void sayHello() {}

constexpr std::array<std::pair<const char *, CommandFunction>, 2> subprograms =
    {{{"hello", sayHello}}};

void print_usage(char **argv) {
  std::cout << std::format("{} <subcommand>", *argv[0]) << '\n' << '\n';
  std::cout << "Allowed subcommands:" << '\n';

  for (auto item : subprograms) {
    std::cout << item.first << '\n';
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    print_usage(argv);
    return -1;
  }

  return 0;
}