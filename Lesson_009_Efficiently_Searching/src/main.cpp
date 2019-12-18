#include <exception>
#include <iostream>
#include <vector>

namespace OT {

  /**
   * Function to invoke when an exception is thrown and unhandled
   * @return void
   */
  void unhandled() {
    std::cout << "Unhandled Exception\n";
    std::abort();
  }

} // namespace OT

// Compile time known value, hence the constexpr.
constexpr int notFound = -1;

/**
 * Linear Search Algorithm to find an element in
 * a given array.
 * @return the index where the element was found
 */
int linearSearch(int element, const int* v, int size) {
  for (int i = 0; i < size; i++) {
    if (v[i] == element) {
      return i;
    }
  }

  return notFound;
}

/**
 * Binary Search Algorithm to find an element in
 * a given sorted array.
 */
int binarySearch(int element, const int* v, int size) {
  int left  = 0;        // point to the first element in the array
  int right = size - 1; // points to the last element in the array

  while (left <= right) {
    int middle = (left + right) / 2; // calculate the middle point @ each step

    if (v[middle] == element) {
      // Found!
      return middle;
    } else if (v[middle] < element) {
      // Adjust search to the right most elements.
      left = middle + 1; // plus 1 because this loop accounts for the current middle
    } else if (v[middle] > element) {
      // Adjust search to the left most elements.
      right = middle - 1; // minus 1 because this loop accounts for the current middle
    }
  }

  return notFound;
}

// Use a template here for practice
template<typename T>
void print(const std::vector<T>& v) {
  unsigned int i = 0;
  std::cout << "[ ";
  for (T e: v) {
    if (++i < v.size()) {
      std::cout << e << ", ";
    } else {
      std::cout << e << " ";
    }
  }
  std::cout << "]\n";
}

int main() {
  // Set up function to hopefully call when
  // "something bad" happened.
  std::set_terminate(OT::unhandled);

  std::vector<int> v{33, 44, 55, 66, 77, 88, 99};
  print(v);

  int toFind;
  std::cout << "Element to search? ";
  std::cin >> toFind;
  int index = linearSearch(toFind, v.data(), v.size());

  if (index != notFound) {
    std::cout << toFind << " found at index " << index << "\n";
  } else {
    std::cout << toFind << " was not found\n";
  }

  return 0;
}
