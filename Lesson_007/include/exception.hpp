#ifndef EXCEPTION_HEADER_
#define EXCEPTION_HEADER_

#include <string>

namespace Exceptions {
  const std::string ARRAY_INDEX_OUT_OF_BOUNDS{"Array index out of bounds."};
}

class IndexOutOfBoundsException: public std::exception {
  public:
  IndexOutOfBoundsException(const char* file, int line): std::exception(), file(file), line(line) {}
  const char* what() const throw() {
    return (Exceptions::ARRAY_INDEX_OUT_OF_BOUNDS + " in file " + this->file + " at line " +
            std::to_string(this->line))
        .c_str();
  }

  private:
  std::string file;
  int line;
};
#define THROW_EXCEPTION_INDEX_OUT_OF_BOUNDS()                                                      \
  throw IndexOutOfBoundsException {                                                                \
    __FILE__, __LINE__                                                                             \
  }

#endif // EXCEPTION_HEADER_