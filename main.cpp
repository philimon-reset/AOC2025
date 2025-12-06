#include "AOC.h"

int main() {
    const vector<pair<string, string>> id_pairs = AOC::extractRangePairFromFile("2a");
    cout << AOC::sumOfInvalidIds(id_pairs);
}