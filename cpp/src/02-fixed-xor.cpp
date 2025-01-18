#include "02-fixed-xor.h"

#include "helper.h"

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <vector>

void calculateFixedXor() {
  std::vector<uint8_t> a =
      helper::hexStrToBytes("1c0111001f010100061a024b53535009181c");
  std::vector<uint8_t> b =
      helper::hexStrToBytes("686974207468652062756c6c277320657965");

  if (a.size() != b.size()) {
    throw std::invalid_argument("Inputs must have equal size");
  }

  std::vector<uint8_t> result;
  result.reserve(a.size());

  for (size_t i = 0; i < a.size(); ++i) {
    result.push_back(a[i] ^ b[i]);
  }

  std::cout << helper::bytesToHex(result) << '\n';
}
