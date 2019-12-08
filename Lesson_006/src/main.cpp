#include <algorithm>
#include <iostream>

const char* getCmdOption(const char** begin, const char** end, std::string const& option) {
  const char** iter = std::find(begin, end, option);
  if (iter != end && ++iter != end) {
    return *iter;
  }

  return 0;
}

bool cmdOptionExists(const char** begin, const char** end, std::string const& option) {
  return std::find(begin, end, option) != end;
}

int main(int argc, char const* argv[]) {
  if (cmdOptionExists(argv, argv + argc, "-h")) {
    std::cout << "help message\n";
  } else {
    std::cout << "you did not specify an argument.\n";
  }

  return 0;
}
