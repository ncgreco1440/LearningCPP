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
#define THROW_EXCEPTION_INDEX_OUT_OF_BOUNDS()                                                      \
  throw IndexOutOfBoundsException {                                                                \
    __FILE__, __LINE__                                                                             \
  }

class IntArray {
  public:
  IntArray(): m_ptr(nullptr), m_size(0){};
  explicit IntArray(unsigned int const size): m_ptr(std::make_unique<int[]>(size)), m_size(size) {}
  IntArray(const IntArray& rhs): m_ptr(std::make_unique<int[]>(rhs.size())), m_size(rhs.size()) {
    for (unsigned int i = 0; i < this->size(); i++) {
      this->m_ptr[i] = rhs[i];
    }
  }
  /**
   * Move Constructor
   * Useful for performance boosts as no deep copy memory allocation must occur
   * You essentially just grab the address of data from source and make
   * destination the new owner of that existing data.
   */
  IntArray(IntArray&& src) {
    this->m_ptr.swap(src.m_ptr); // effectively the same thing as std::swap(m_ptr, src.m_ptr)
    this->m_size = src.m_size;

    // In case that the source was a real object, we should make sure it is cleaned up
    src.m_ptr.reset();
    src.m_size = 0;
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
      THROW_EXCEPTION_INDEX_OUT_OF_BOUNDS();
    }
  }

  inline int operator[](const unsigned int index) const {
    if (index <= m_size - 1) {
      return m_ptr[index];
    } else {
      THROW_EXCEPTION_INDEX_OUT_OF_BOUNDS();
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

  /**
   * Traditional overloaded assignment operator function
   */
  // IntArray& operator=(const IntArray& rhs) {
  //   if (this != &rhs) {
  //     m_ptr.reset();
  //     m_ptr  = std::make_unique<int[]>(rhs.size());
  //     m_size = rhs.size();
  //     for (unsigned int i = 0; i < this->size(); i++) {
  //       this->m_ptr[i] = rhs[i];
  //     }
  //   }

  //   return *this;
  // }

  /**
   * copy - swap idiom
   * VS Code will report useage of this function as an error, but it will compile.
   * @see [GitHub Ticket here](https://github.com/microsoft/vscode-cpptools/issues/4595)
   */
  friend void swap(IntArray& lhs, IntArray& rhs) noexcept {
    // Memberwise swap
    std::swap(lhs.m_ptr, rhs.m_ptr);
    std::swap(lhs.m_size, rhs.m_size);
  }

  /**
   * Liberal overloaded assignment operator function
   * leverages the copy - swap idiom
   */
  IntArray& operator=(IntArray rhs) {
    swap(*this, rhs); // red squiggles may/will appear here, false positive this is legit code

    return *this;
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

  a    = b;
  a[1] = 5000;
  b[2] = 5001;

  std::cout << "a = " << a << "\n";
  std::cout << "b = " << b << "\n";
  std::cout << "a = " << a << "\n";

  // To use the move constructor, you can create a new instance just like you would the
  // copy constructor, however you first call std::move and use it's result as an
  // argument
  IntArray d{std::move(a)};
  std::cout << "d = " << d << "\n";

  char y;
  std::cin >> y;
  return 0;
}
