#include <cstdint>
#include <iomanip>
#include <ios>
#include <sstream>
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
    std::string byteString = hex.substr(i, 2);

    // Hex to byte
    uint8_t byte = static_cast<uint8_t>(std::stoi(byteString, nullptr, 16));
    byteArray.push_back(byte);
  }

  return byteArray;
}

std::string bytesToHex(const std::vector<uint8_t>& bytes) {
  std::stringstream ss;
  ss << std::hex;

  for (size_t i = 0; i < bytes.size(); ++i) {
    ss << std::setw(2) << std::setfill('0')
       << static_cast<unsigned int>(bytes[i]);
  }

  return ss.str();
}

std::string bytesToString(const std::vector<uint8_t>& bytes) {
  std::stringstream ss;

  for (size_t i = 0; i < bytes.size(); ++i) {
    ss << bytes[i];
  }

  return ss.str();
}

} // namespace helper
