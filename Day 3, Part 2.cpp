#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// traverse a path.
// start at index 0 in line 1
// move index right 3 before moving to next line
// if you reach right side, loop back to staring index
// if the end point is a tree, increment number of trees
// when you reach the bottom, total number of trees
// determine for each slope:
// Right 1, down 1.
// Right 3, down 1. 
// Right 5, down 1.
// Right 7, down 1.
// Right 1, down 2. 

int main()
{
    string line;
    int treesPath1, treesPath2, treesPath3, treesPath4, treesPath5;
    int path1Ind, path2Ind, path3Ind, path4Ind, path5Ind;
    int lineNum, product;

    treesPath1 = 0;
    treesPath2 = 0;
    treesPath3 = 0;
    treesPath4 = 0;
    treesPath5 = 0;
    path1Ind = 0;
    path2Ind = 0;
    path3Ind = 0;
    path4Ind = 0;
    path5Ind = 0;
    product = 0;

    //get the file
    ifstream passwordFile1;
    passwordFile1.open("../input.txt", ios::in);

    //for right 1, down 1:
    while (getline(passwordFile1, line)) {

        //do you hit a tree?
        if (line[path1Ind] == '#') {
            treesPath1++;
        }

        //get the next index
        //if not going to hit right side, increment by 3
        if (path1Ind < line.length() - 1) {
            path1Ind += 1;
        }
        //if going to hit the right side, find out how many are left to the end and ind is 0 + 3-remaining 
        else {
            if (path1Ind == line.length() - 1)
                path1Ind = 0;
        }
    }

    //get the file
    ifstream passwordFile2;
    passwordFile2.open("../input1.txt", ios::in);

    //for right 3, down 1:
    while (getline(passwordFile2, line)) {

        //do you hit a tree?
        if (line[path2Ind] == '#') {
            treesPath2++;
        }

        //get the next index
        //if not going to hit right side, increment by 3
        if (path2Ind < line.length() - 3) {
            path2Ind += 3;
        }
        //if going to hit the right side, find out how many are left to the end and ind is 0 + 3-remaining 
        else {
            if (path2Ind == line.length() - 3)
                path2Ind = 0;
            else if (path2Ind == line.length() - 2)
                path2Ind = 1;
            else if (path2Ind == line.length() - 1)
                path2Ind = 2;
        }
    }

    //get the file
    ifstream passwordFile3;
    passwordFile3.open("../input2.txt", ios::in);

    //for right 5, down 1:
    while (getline(passwordFile3, line)) {

        //do you hit a tree?
        if (line[path3Ind] == '#') {
            treesPath3++;
        }

        //get the next index
        //if not going to hit right side, increment by 3
        if (path3Ind < line.length() - 5) {
            path3Ind += 5;
        }
        //if going to hit the right side, find out how many are left to the end and ind is 0 + 3-remaining 
        else {
            if (path3Ind == line.length() - 5)
                path3Ind = 0;
            else if (path3Ind == line.length() - 4)
                path3Ind = 1;
            else if (path3Ind == line.length() - 3)
                path3Ind = 2;
            else if (path3Ind == line.length() - 2)
                path3Ind = 3;
            else if (path3Ind == line.length() - 1)
                path3Ind = 4;
        }
    }

    //get the file
    ifstream passwordFile4;
    passwordFile4.open("../input3.txt", ios::in);

    //for right 7, down 1:
    while (getline(passwordFile4, line)) {

        //do you hit a tree?
        if (line[path4Ind] == '#') {
            treesPath4++;
        }

        //get the next index
        //if not going to hit right side, increment by 3
        if (path4Ind < line.length() - 7) {
            path4Ind += 7;
        }
        //if going to hit the right side, find out how many are left to the end and ind is 0 + 3-remaining 
        else {
            if (path4Ind == line.length() - 7)
                path4Ind = 0;
            else if (path4Ind == line.length() - 6)
                path4Ind = 1;
            else if (path4Ind == line.length() - 5)
                path4Ind = 2;
            else if (path4Ind == line.length() - 4)
                path4Ind = 3;
            else if (path4Ind == line.length() - 3)
                path4Ind = 4;
            else if (path4Ind == line.length() - 2)
                path4Ind = 5;
            else if (path4Ind == line.length() - 1)
                path4Ind = 6;
        }
    }

    //get the file
    ifstream passwordFile5;
    passwordFile5.open("../input4.txt", ios::in);
    lineNum = 1;
    //for right 1, down 2:
    while (getline(passwordFile5, line)) {

        if (lineNum % 2 != 0) {
            //do you hit a tree?
            if (line[path5Ind] == '#') {
                treesPath5++;
            }

            //get the next index
            //if not going to hit right side, increment by 3
            if (path5Ind < line.length() - 1) {
                path5Ind += 1;
            }
            //if going to hit the right side, find out how many are left to the end and ind is 0 + 3-remaining 
            else {
                if (path5Ind == line.length() - 1)
                    path5Ind = 0;
            }
        }
        lineNum++;
    }
    product = treesPath1 * treesPath2 * treesPath3 * treesPath4 * treesPath5;

    cout << product << endl;

    return 0;
}

