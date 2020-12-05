#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//recursion binary search F = first half, B = last half for rows
//l means left half and r means right half for columns
//get row and column then calc seatID (row*8 + column)

int findRow(string lineInput);
int findColumn(string lineInput);

int main()
{
    string line;
    int row, column, maxSeatID, currSeat;
    maxSeatID = 0;
    currSeat = 0;

    //get the file
    ifstream seatAssign;
    seatAssign.open("../input.txt", ios::in);

    //go through line by line
    while (getline(seatAssign, line)) {
        row = findRow(line);
        column = findColumn(line);
        currSeat = (row * 8) + column;
        if (currSeat > maxSeatID) {
            maxSeatID = currSeat;
        }
    }

    cout << maxSeatID << endl;

    return 0;
}


int findRow(string lineInput) {
    int low = 0;
    int high = 127;
    int mid = (high + low) / 2;

    for (int i = 0; i < 7; i++) {
        if (lineInput[i] == 'F') {
            high = mid;
            mid = (high + low) / 2;
        }
        else if (lineInput[i] == 'B') {
            low = mid + 1;
            mid = (high + low) / 2;
        }

    }
    if (high == low)
        return low;
    else
        cout << "error" << endl;
}

int findColumn(string lineInput) {
    int low = 0;
    int high = 7;
    int mid = (high + low) / 2;

    for (int i = 7; i < 10; i++) {
        if (lineInput[i] == 'L') {
            high = mid;
            mid = (high + low) / 2;
        }
        else if (lineInput[i] == 'R') {
            low = mid + 1;
            mid = (high + low) / 2;
        }

    }
    if (high == low)
        return low;
    else
        cout << "error" << endl;
}

