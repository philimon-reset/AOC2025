#include "AOC.h"

int main() {
    const vector<string> banks = AOC::extractFromFile("3a");
    cout << AOC::getMaxJoltageImproved(banks);
}