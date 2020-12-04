#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* traverse a path.
* start at index 0 in line 1
* move index right 3 before moving to next line
* if you reach right side, loop back to staring index
* if the end point is a tree, increment number of trees
* when you reach the bottom, total number of trees
*/

int main()
{
    string line;
    int treeCount, pathInd, beforeEnd;

    treeCount = 0;
    pathInd = 0;
    beforeEnd = 0;

    //get the file
    ifstream passwordFile;
    passwordFile.open("../input.txt", ios::in);

    while (getline(passwordFile, line)) {

        //do you hit a tree?
        if (line[pathInd] == '#') {
            treeCount++;
        }

        //get the next index
        //if not going to hit right side, increment by 3
        if (pathInd < line.length() - 3) {
            pathInd += 3;
        }
        //if going to hit the right side, find out how many are left to the end and ind is 0 + 3-remaining 
        else {
            if (pathInd == line.length() - 3)
                pathInd = 0;
            else if (pathInd == line.length() - 2)
                pathInd = 1;
            else if (pathInd == line.length() - 1)
                pathInd = 2;
        }
    }

    cout << treeCount << endl;

    return 0;
}