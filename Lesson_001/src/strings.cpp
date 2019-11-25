#include <string>

std::string printName(const std::string first, const std::string last) {
  return last + ", " + first;
}

std::string printName(const std::string first, const std::string last,
  const std::string middle) {
  return last + ", " + first + " " + middle + ".";
}

unsigned int nameLength(const std::string first) {
  return first.length();
}

unsigned int nameLength(const std::string first, const std::string last) {
  return first.length() + last.length();
}

unsigned int nameLength(const std::string first, const std::string last,
  const std::string middle) {
  return first.length() + last.length() + middle.length();
}