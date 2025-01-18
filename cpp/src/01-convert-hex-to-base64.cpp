#include "01-convert-hex-to-base64.h"
#include "helper.h"
#include <cppcodec/base64_rfc4648.hpp>

#include <iostream>
#include <vector>

void convertHexToBase64() {
  constexpr const char* input =
      "49276d206b696c6c696e6720796f757220627261696e206c696b6"
      "5206120706f69736f6e6f7573206d757368726f6f6d";

  std::vector<uint8_t> byteArray = helper::hexStrToBytes(input);
  std::string          b64String = cppcodec::base64_rfc4648::encode(byteArray);

  std::cout << b64String << '\n';
}
