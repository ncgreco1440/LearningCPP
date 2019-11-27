#include <iostream>
#include <vector>

/**
 * Just practicing the use of typedef
 * These are arguably unnecessary in day to day cpp development
 */
typedef std::vector<std::string> Vector_Str;
typedef std::string String;

int main(int argc, char const *argv[])
{
  /** 
   * Use the range initializer, 
   * this saves you the time of having to write a for loop
   * 
   * Start at argv + 1 because the first c-string in argv will be 
   * the full filepath of the program.
   */
  Vector_Str args{argv + 1, argv + argc};

  std::cout << "Hello, World!\n";
  std::cout << "CLI Arguments...\n";
  
  // Try to avoid native for-loops when possible. 
  for (String str:args) {
    std::cout << str << "\n";
  }

  return 0;
}
