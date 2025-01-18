#ifndef HELPER_H
#define HELPER_H

#include <vector>

namespace helper {

std::vector<uint8_t> hexStrToBytes(const std::string& hex);
std::string          bytesToHex(const std::vector<uint8_t>& bytes);

} // namespace helper

#endif
