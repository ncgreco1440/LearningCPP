#include <iostream>
#include <vector>

int typeBitSize(unsigned long long typeBitSize) {
    return typeBitSize * 8;
}

int main(int argc, char* argv[])
{
    // Leverage a vector rather than raw array for ease of usability later on.
    std::vector<std::string> args;
    std::cout << "Number of Arguments..." << argc << "\n";
    for (int i = 0; i < argc; i++) {
        args.push_back(argv[i]);
    }

    for (int i = 0; i < args.size(); i++) {
        std::cout << (args[i]) << "\n";
    }

    std::cout << "Int is a " << typeBitSize(sizeof(int)) << "bit data type.\n";
    std::cout << "Float is a " << typeBitSize(sizeof(float)) << "bit data type.\n";
    std::cout << "Double is a " << typeBitSize(sizeof(double)) << "bit data type.\n";
    std::cout << "Char is a " << typeBitSize(sizeof(char)) << "bit data type.\n";
    std::cout << "Bool is a " << typeBitSize(sizeof(bool)) << "bit data type.\n";
    return 0;
}