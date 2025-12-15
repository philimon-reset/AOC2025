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

vector<pair<string, string>> AOC::extractRangePairFromFile(const string& fileName)
{
    ifstream mFile(fileName);
    vector<pair<string, string>> container;
    if (mFile.is_open())
    {
        string line;
        while (getline(mFile, line, ','))
        {
            size_t end = line.find('-');
            container.emplace_back(line.substr(0, end), line.substr(end + 1));
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

long AOC::sumOfInvalidIds(vector<pair<string, string>> id_pairs)
{
    long invalid_sum = 0;
    unordered_set<long> check;
    for (auto [start, end] : id_pairs)
    {
        long first = stol(start);
        long last = stol(end);
        while (first <= last)
        {
            string cur = std::to_string(first);
            if (checkDuplicateSequence(cur))
                invalid_sum += first;
            first++;
        }
    }
    return invalid_sum;
}

bool AOC::checkDuplicateSequence(const string& val)
{
    string cur = (val + val).substr(1, (val.size() * 2) - 2);
    return cur.find(val) != string::npos;
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

int AOC::getMaxJoltage(vector<string> banks)
{
    int joltage = 0;
    for (const string& str: banks)
    {
        int l = 0;
        int rmax = 0;
        int lval = 0;
        int rval = 0;
        for (int r = 1; r < str.size(); r++)
        {
            lval = str.at(l) - '0';
            rval = str.at(r) - '0';
            rmax = max(rmax, rval);
            // if (lval >= rval && rval == 9)
            //     break;
            if (rval > lval && r < str.size() - 1)
            {
                rmax = str.at(r + 1) - '0';
                l = r;
            }
        }
        string curval({char('0' + lval), char('0' + rmax)});
        joltage += stoi(curval);
    }
    return joltage;
}

int AOC::getMaxJoltageImproved(vector<string> banks)
{
    int joltage = 0;
    for (const string& str: banks)
    {
        int l = 0;
        int rmax = 0;
        int lval = 0;
        int rval = 0;
        for (int r = 1; r < str.size(); r++)
        {
            lval = str.at(l) - '0';
            rval = str.at(r) - '0';
            rmax = max(rmax, rval);
            // if (lval >= rval && rval == 9)
            //     break;
            if (rval > lval && r < str.size() - 1)
            {
                rmax = str.at(r + 1) - '0';
                l = r;
            }
        }
        string curval({char('0' + lval), char('0' + rmax)});
        joltage += stoi(curval);
    }
    return joltage;
}
