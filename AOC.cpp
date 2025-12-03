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
            if (dial + rotation == 100)
                dial = 0;
            else if (dial + rotation > 99)
                dial = (rotation + dial) - 100;
            else
                dial += rotation;
            break;
        case 'L':
            if (dial - rotation < 0)
                dial = 100 - (max(rotation, dial) - min(rotation, dial));
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