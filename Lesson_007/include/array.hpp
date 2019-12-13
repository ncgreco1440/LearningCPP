#ifndef ARRAY_HEADER_
#define ARRAY_HEADER_

#include "exception.hpp"
#include <iostream>
#include <memory>

template<typename T>
class Array {
  public:
  Array(): m_ptr(nullptr), m_size(0){};
  explicit Array(unsigned int const size): m_ptr(std::make_unique<T[]>(size)), m_size(size) {}
  Array(const Array& rhs): m_ptr(std::make_unique<T[]>(rhs.size())), m_size(rhs.size()) {
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
  Array(Array&& src) {
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

  inline T& operator[](const unsigned int index) {
    if (index <= m_size - 1) {
      return m_ptr[index];
    } else {
      THROW_EXCEPTION_INDEX_OUT_OF_BOUNDS();
    }
  }

  inline T operator[](const unsigned int index) const {
    if (index <= m_size - 1) {
      return m_ptr[index];
    } else {
      THROW_EXCEPTION_INDEX_OUT_OF_BOUNDS();
    }
  }

  friend std::ostream& operator<<(std::ostream& os, const Array<T>& a) {
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
   * copy - swap idiom
   * VS Code will report useage of this function as an error, but it will compile.
   * @see [GitHub Ticket here](https://github.com/microsoft/vscode-cpptools/issues/4595)
   */
  friend void swap(Array& lhs, Array& rhs) noexcept {
    // Memberwise swap
    std::swap(lhs.m_ptr, rhs.m_ptr);
    std::swap(lhs.m_size, rhs.m_size);
  }

  /**
   * Liberal overloaded assignment operator function
   * leverages the copy - swap idiom
   */
  Array& operator=(Array rhs) {
    swap(*this, rhs); // red squiggles may/will appear here, false positive this is legit code

    return *this;
  }

  private:
  std::unique_ptr<T[]> m_ptr;
  unsigned int m_size;
};

#endif // ARRAY_HEADER_