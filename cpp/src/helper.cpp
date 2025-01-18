#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

namespace helper {

std::vector<uint8_t> hexStrToBytes(const std::string& hex) {
  if (hex.length() % 2 != 0) {
    throw std::invalid_argument("Hex string must have an even length");
  }

  std::vector<uint8_t> byteArray;

  // Reserve space to avoid unnecessary allocations
  byteArray.reserve(hex.length() / 2);

  for (size_t i = 0; i < hex.length(); i += 2) {
    auto byteString = hex.substr(i, 2);

    // Hex to byte
    uint8_t byte = static_cast<uint8_t>(std::stoi(byteString, nullptr, 16));
    byteArray.push_back(byte);
  }

  return byteArray;
}

} // namespace helper
