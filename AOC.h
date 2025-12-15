#ifndef SETUP_AOC_H
#define SETUP_AOC_H
#include <iostream>
#include <fstream>
#include <unordered_set>

using std::cout, std::endl, std::ifstream, std::string, std::vector, std::ostream, std::unordered_map, std::stol ,
    std::stoi, std::min, std::max, std::pair, std::reverse, std::to_string, std::unordered_set;


class AOC
{
public:
    // Helper methods
    static vector<string> extractFromFile(string filename);
    static vector<pair<string, string>> extractRangePairFromFile(const string& fileName);
    static vector<long> getNumberOfDigits(long num);
    // First Day
    static int findSafeCode(vector<string> instructions);
    static int findSafeCodeOverLap(vector<string> instructions);
    // Second Day
    static long sumOfInvalidIds(vector<pair<string, string>> id_pairs);
    static bool checkDuplicateSequence(const string& val);
    // Third Day
    static int getMaxJoltage(vector<string> banks);
    static int getMaxJoltageImproved(vector<string> banks);
};


// Helper templates for nicer printing
template <typename>
struct is_std_vector : std::false_type
{
};

template <typename U, typename Alloc>
struct is_std_vector<std::vector<U, Alloc>> : std::true_type
{
};

template <typename T>
inline constexpr bool is_std_vector_v = is_std_vector<T>::value;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec)
{
    os << "[";
    if constexpr (is_std_vector_v<T>)
    {
        os << "\n\t";
    }
    for (size_t i = 0; i < vec.size(); ++i)
    {
        os << vec[i];
        if (i != vec.size() - 1)
            os << ", ";
    }
    if constexpr (is_std_vector_v<T>)
    {
        os << "\n";
    }
    os << "]";
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, const unordered_map<T, int>& mp)
{
    for (const auto& [key, value] : mp)
    {
        os << key << " : " << value << endl;
    }
    os << "=======\n";
    return os;
}


#endif //SETUP_AOC_H
