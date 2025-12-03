#include "AOC.h"

int main() {
    const vector<string> instructions = AOC::extractFromFile("1a_example");
    cout << AOC::findSafeCode(instructions);
}


