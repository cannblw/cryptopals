#include "03-single-byte-xor.h"

#include "helper.h"

#include <cstdint>
#include <vector>

std::vector<uint8_t> calculateXor(std::vector<uint8_t> input, uint8_t byte) {
  std::vector<uint8_t> result;
  result.reserve(input.size());

  for (const auto& c : input) {
    result.push_back(c ^ byte);
  }

  return result;
}

void singleByteXor() {
  std::vector<uint8_t> input = helper::hexStrToBytes(
      "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736");

  for (int i = 0; i < 256; ++i) {
    std::vector<uint8_t> xorString = calculateXor(input, i);

    // TODO: Calculate score

    // TODO: Print string with the highest score
  }
}
