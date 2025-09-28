// #include <iostream>
// #include <filesystem>
// #include "./src/app/processes/ProcessManagement.hpp"
// #include "./src/app/processes/Task.hpp"

// using namespace std;
// namespace fs = std::filesystem;
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main() {
    for (auto& p : fs::directory_iterator(".")) {
        std::cout << p.path() << "\n";
    }
}
