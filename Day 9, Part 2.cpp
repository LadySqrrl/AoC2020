#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	ifstream numbers;
	string line;
	vector<int> nums = {};
	vector<int> currNums = { 0 };
	int num, target, currSum, activeNum, finalSum;
	bool found = false;
	int smallest = 0;
	int largest = 0;
	finalSum = 0;
	num = 0;
	target = 57195069;
	currSum = 0;
	activeNum = 0;

	//fill nums vector with all nums
	numbers.open("../day9input.txt", ios::in);
	while (getline(numbers, line)) {
		num = 0;
		stringstream lineNum(line);
		lineNum >> num;
		nums.push_back(num);
	}
	numbers.close();
	int vectSize = nums.size();

	//start at point 0, add until it equals or is larger than target num
	int currInd = 0;
	int startPoint = 0;
	while (found == false) {
		//if it's smaller, keep rolling and adding to the sum and list
		if (currSum < target) {
			activeNum = nums[currInd];
			currSum += activeNum;
			currNums.push_back(activeNum);
			currInd++;
		}
		//if it is larger, iterate up to the next start point number and start over
		else if (currSum > target) {
			startPoint++;
			currNums = {};
			currSum = 0;
			currInd = startPoint;
		}
		else if (currSum == target) {
			//if it equals the target mark found true
			found = true;
			cout << "found it" << endl;
		}
	}

	//get the smallest number of the currNums vector and the largest and add them
	int currNumsSize = currNums.size();
	smallest = currNums[0];
	for (int i = 0; i < currNumsSize; i++) {
		if (currNums[i] < smallest) {
			smallest = currNums[i];
		}
		if (currNums[i] > largest) {
			largest = currNums[i];
		}
	}

	finalSum = smallest + largest;
	cout << finalSum << endl;

	return 0;
}
