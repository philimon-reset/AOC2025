#include "AOC.h"

int main() {
    const vector<pair<long, long>> id_pairs = AOC::extractRangePairFromFile("2a");
    cout << AOC::sumOfInvalidIds(id_pairs);
}