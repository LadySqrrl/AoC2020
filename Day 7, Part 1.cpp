#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//PLAN:
//3 vectors: curentColor, nextColor, finalList
//for i in currentColor vector
	//open file
	//set target color to the item in the vector
	//iterate thorugh rules doc line by line
	//if target color is found in the line, make string of first color
	//check to make sure first color is not in the next list or final list vectors already
	//append first color to next color vector and final vector
	//reset current color to empty string
//when done for current color vector
	//make current color vector = next color vector
	//empty next color vector
	//close the file 
//go thorugh new current color vecotor again
//repeat process until current comes back empty


int main()
{
	ifstream bagRules;
	string line;
	string targetBag = "";
	string containerColor;
	vector<string> currColorList = {"shiny gold"};
	vector<string> nextColorList = {};
	vector<string> finalList = {};
	int finalAns, currListSize, nextListSize;
	currListSize = currColorList.size();

	//check if current color is empty (ie, reached the end)
	while (currListSize > 0) {
		for (int i = 0; i < currListSize; i++) {
			//open file
			bagRules.open("../input.txt", ios::in);
			//set target color to the ith position in the vector
			targetBag = currColorList[i];

			//iterate through line by line
			while (getline(bagRules, line)) {

				//search string for target color
				size_t found = line.find(targetBag);
				//need to address it not being in the first position still!!!!
				// maybe add to if statement found != position 1?
				if (found != string::npos && found != 0) {
					//get the color of the container bag and add it to list of colors to search
					stringstream ss(stringstream::in | stringstream::out);
					for (int j = 0; j < 2; j++) {
						ss << line;

						string word;
						ss >> word;
						containerColor.append(word);
						containerColor.append(" ");
					}
					//if not in next color vector, add to vector (if can't fix...maybe just add all and remove dupes later?
					if (find(nextColorList.begin(), nextColorList.end(), containerColor) == nextColorList.end()) {
						nextColorList.push_back(containerColor);
					}
					if (find(finalList.begin(), finalList.end(), containerColor) == finalList.end()) {
						finalList.push_back(containerColor);
					}

				}
				containerColor = "";
			}
			bagRules.close();
		}
		//close file
		//get next list
		currColorList = {};
		nextListSize = nextColorList.size();
		for (int k = 0; k < nextListSize; k++) {
			currColorList.push_back(nextColorList[k]);
		}
		nextColorList = {};
		currListSize = currColorList.size();
	}

	finalAns = finalList.size();

	cout << finalAns << endl;

	return 0;
}
