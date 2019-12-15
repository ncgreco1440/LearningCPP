#include <exception>
#include <iostream>

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

int main() {
  std::set_terminate(OT::unhandled);
  std::cout << "Hello world from MSVC Compiler!\n";
  throw 6;
  return 0;
}
