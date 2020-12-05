#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//binary search
//l means left half and r means right half for columns
//get row and column then calc seatID (row*8 + column)

int findRow(string lineInput);
int findColumn(string lineInput);
void selectionSort(int arr[], int arrSize);

int main()
{
    string line;
    int row, column, maxSeatID, currSeat, lineNum, mySeat;
    maxSeatID = 0;
    currSeat = 0;
    lineNum = 0;
    mySeat = 0;
    int idArr[799];

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
        idArr[lineNum] = currSeat;
        lineNum++;
    }

    selectionSort(idArr, 799);

    for (int q = 0; q < 799; q++) {
        if ((idArr[q] != idArr[q - 1] + 1) || (idArr[q] != idArr[q + 1] - 1)) {
            cout << idArr[q] << endl;
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

int findIndexofMin(int arr[], int low, int high) {
    int min, minInd;
    min = arr[low];
    minInd = low;
    for (int i = low + 1; i <= high; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minInd = i;
        }
    }
    return minInd;
}

void selectionSort(int arr[], int arrSize) {
    int i, minInd;
    for (i = 0; i < arrSize; i++) {
        minInd = findIndexofMin(arr, i, arrSize - 1);
        swap(arr[i], arr[minInd]);
    }
}