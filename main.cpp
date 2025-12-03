#include "AOC.h"

int main() {
    const vector<string> instructions = AOC::extractFromFile("1a");
    cout << AOC::findSafeCode(instructions);
}