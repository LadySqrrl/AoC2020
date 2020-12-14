#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
//PLAN:
//for line in file, if the line number, run function determining if any of the previous 25 (in preamble) sum to that number
//while it returns true, update preamble and keep going
//when it returns false, print out the number from the line

bool sums(int num, vector<int> preamble);

int main()
{
    ifstream numbers;
    string line;
    vector<int> preamble = {};
    bool foundSum = true;
    int num, currLine;
    num = 0;
    currLine = 0;

    //get the initial preamble set
    numbers.open("../day9input.txt", ios::in);
    while (getline(numbers, line)) {
        currLine++;
        if (currLine < 26) {
            stringstream preambleLine(line);
            preambleLine >> num;
            preamble.push_back(num);
        }
        else
            numbers.close();
    }
    
    currLine = 0;
    numbers.open("../day9input.txt", ios::in);
    while (getline(numbers, line)) {
        currLine++;
        num = 0;
        if (currLine > 25) {
            //check to see if the number is the sum of two of the preamble integers
            stringstream lineNum(line);
            lineNum >> num;
            foundSum = sums(num, preamble);
            if (foundSum == true)
                cout << "still got matches! " << endl;
            else
                cout << "found the one that doesn't have a sum! " << num << endl;
        }
        preamble.erase(preamble.begin());
        preamble.push_back(num);
    }
    return 0;
}

bool sums(int num, vector<int> preamble) {
    int preambleSize, sumsFound;
    preambleSize = preamble.size();
    sumsFound = 0;

    //use two-sum problem to go through the list with num as the target
    for (int i = 0; i < preambleSize; i++) {
        for (int j = 1; j < preambleSize; j++) {
            if (preamble[i] + preamble[j] == num) {
                sumsFound++;
            }
        }
    }
    if (sumsFound > 0)
        return true;
    else
        return false;
}