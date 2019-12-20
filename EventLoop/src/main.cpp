#include "nvapi.h"
#include <iostream>
#include <string>

const std::string KILL_COMMAND{"quit"};
const std::string ALT_KILL_COMMAND{"exit"};
bool quit = false;

int main() {
  std::string currentCommand;

  int result = NvAPI_Initialize();
  if (result == _NvAPI_Status::NVAPI_OK) {
    std::cout << "NvAPI successfully initialized!\n";
  }

  std::cout << "etc etc\n";

  while (!quit) {
    std::cout << ">>> ";
    std::getline(std::cin, currentCommand);
    if (currentCommand == KILL_COMMAND || currentCommand == ALT_KILL_COMMAND) {
      quit = true;
      continue; // stop the current loop and quit
    }

    std::cout << "The command you entered: " << currentCommand << "\n";
  }

  return 0;
}
