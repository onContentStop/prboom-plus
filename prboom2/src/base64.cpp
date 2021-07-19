#include "base64.hpp"

#include <string_view>

// in a true base64 implementation, the last char would be '/'.
// however, this is used for file names, which cannot contain
// that character.
constexpr std::string_view base64_chars{
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-"};

std::string base64_of(std::string_view str) {
  std::string out;
  std::uint32_t val = 0;
  std::int32_t valb = -6;
  for (char c : str) {
    val = (val << 8) + c;
    valb += 8;
    while (valb >= 0) {
      out.push_back(base64_chars[(val >> valb) & 0x3F]);
      valb -= 6;
    }
  }
  if (valb > -6) {
    out.push_back(base64_chars[((val << 8) >> (valb + 8)) & 0x3F]);
  }
  while (out.size() % 4 != 0) {
    out.push_back('=');
  }
  return out;
}
