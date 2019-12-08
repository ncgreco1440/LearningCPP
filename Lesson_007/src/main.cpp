/**
 * Pluralsight Course
 * Introduction to Data Structures and Algorithms in C++
 *
 * Overview:
 * ---
 * Intro to Arrays
 * Safe Array Memory Management
 * Element access and bounds checking
 * Other practical coding techniques
 */

// #include <cassert>
#include <iostream>
#include <memory>
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

class IntArray {
  public:
  IntArray(): m_ptr(nullptr), m_size(0){};
  explicit IntArray(unsigned int const size): m_ptr(std::make_unique<int[]>(size)), m_size(size) {}
  IntArray(const IntArray& rhs): m_ptr(std::make_unique<int[]>(rhs.size())), m_size(rhs.size()) {
    for (unsigned int i = 0; i < this->size(); i++) {
      this->m_ptr[i] = rhs[i];
    }
  }

  inline unsigned int size() const {
    return this->m_size;
  }

  inline bool empty() const {
    return this->m_size == 0;
  }

  inline int& operator[](const unsigned int index) {
    if (index <= m_size - 1) {
      return m_ptr[index];
    } else {
      throw IndexOutOfBoundsException{"", 1};
    }
  }

  inline int operator[](const unsigned int index) const {
    if (index <= m_size - 1) {
      return m_ptr[index];
    } else {
      throw IndexOutOfBoundsException{"", 1};
    }
  }

  friend std::ostream& operator<<(std::ostream& os, const IntArray& a) {
    os << "[ ";
    for (unsigned int i = 0; i < a.size(); i++) {
      if (i != a.size() - 1) {
        os << a[i] << ", ";
      } else {
        os << a[i] << " "; // no trailing comma
      }
    }
    os << "]";

    return os;
  }

  private:
  std::unique_ptr<int[]> m_ptr;
  unsigned int m_size;
};

int main() {
  std::cout << "creating a array containing 0 elements\n";
  IntArray a{};
  std::cout << "a.size() is " << a.size() << "\n";
  // assert(a.empty());
  std::cout << "-------------------------------\n";

  std::cout << "creating a array containing 10 elements\n";
  IntArray b{10};
  std::cout << "b.size() is " << b.size() << "\n";
  // assert(!b.empty());

  for (unsigned int i = 0; i < b.size(); i++) {
    b[i] = i * 5;
  }

  {
    IntArray c{b};
    c[1] = 100;
    std::cout << "c = " << c << "\n";
  }

  try {
    std::cout << b[15] << std::endl;
  } catch (const IndexOutOfBoundsException& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "b = " << b << "\n";

  char y;
  std::cin >> y;
  return 0;
}
