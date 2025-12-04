#include "AOC.h"

vector<string> AOC::extractFromFile(string fileName)
{
    ifstream mFile(fileName);
    vector<string> container;
    if (mFile.is_open())
    {
        string line;
        while (getline(mFile, line))
        {
            container.emplace_back(line);
        }
        mFile.close();
    }
    return container;
}

vector<pair<long, long>> AOC::extractRangePairFromFile(const string& fileName)
{
    ifstream mFile(fileName);
    vector<pair<long, long>> container;
    if (mFile.is_open())
    {
        string line;
        while (getline(mFile, line, ','))
        {
            size_t end = line.find('-');
            long first = stol(line.substr(0, end));
            long second = stol(line.substr(end + 1));
            container.emplace_back(first, second);
        }
        mFile.close();
    }
    return container;
}


int AOC::findSafeCode(vector<string> instructions)
{
    int dial = 50;
    int password = 0;
    for (const string str : instructions)
    {
        const char direction = str.at(0);
        const string full_direction = direction == 'L' ? "Left" : "Right";
        const int rotation = stoi(str.substr(1)) % 100;
        switch (direction)
        {
        case 'R':
            if (dial + rotation > 99)
                dial = (rotation + dial) - 100;
            else
                dial += rotation;
            break;
        case 'L':
            if (dial - rotation < 0)
                dial = 100 - (rotation - dial);
            else
                dial -= rotation;
            break;
        default:
            break;
        }
        if (dial == 0)
            password += 1;
        cout << "Rotate: " <<  full_direction << ", " << rotation << " | Dial: " << dial << endl;
    }
    return password;
}

int AOC::findSafeCodeOverLap(vector<string> instructions)
{
    int dial = 50;
    int password = 0;
    for (const string str : instructions)
    {
        int prev_dial = dial;
        const char direction = str.at(0);
        const string full_direction = direction == 'L' ? "Left" : "Right";
        int rotation = stoi(str.substr(1));
        password += rotation / 100;
        rotation %= 100;
        switch (direction)
        {
        case 'R':
            if (dial + rotation > 99)
                dial = (rotation + dial) - 100;
            else
                dial += rotation;
            if ((dial < prev_dial && prev_dial != 0) || dial == 0)
                password += 1;
            break;
        case 'L':
            if (dial - rotation < 0)
                dial = 100 - (rotation - dial);
            else
                dial -= rotation;
            if ((dial > prev_dial && prev_dial != 0) || dial == 0)
                password += 1;
            break;
        default:
            break;
        }
        cout << "Rotate: " <<  full_direction << ", " << rotation << " | Dial: " << dial << endl;
    }
    return password;
}

long AOC::sumOfInvalidIds(vector<pair<long, long>> id_pairs)
{
    long invalid_sum = 0;
    for (auto [start, end] : id_pairs)
    {
        while (start <= end)
        {
            vector<long> digits = AOC::getNumberOfDigits(start);
            long num_size = digits.size();
            if (num_size % 2 == 0)
            {
                vector<long> front = {digits.begin(), digits.begin() + (num_size / 2)};
                vector<long> back = {digits.begin() + (num_size / 2), digits.end()};
                if (front == back)
                    invalid_sum += start;
            }
            start++;
        }
    }
    return invalid_sum;
}

vector<long> AOC::getNumberOfDigits(long num)
{
    vector<long> res;
    while (num > 0)
    {
        res.push_back(num % 10);
        num /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
