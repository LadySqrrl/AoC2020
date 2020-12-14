#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*PLAN
~Fill vector with all jolts
~sort 
~find all the incidents of a 1 jolt difference
~find all the incidents of a 3 jolt difference
~multiply them*/

int main()
{
	ifstream joltsList;
	string line;
	vector<int> joltsVect1, joltsVect2;
	int num, totalLines, currLine, oneJolt, threeJolt, product;
	num = 0;
	totalLines = 0;
	currLine = 0;
	oneJolt = 0;
	threeJolt = 0;

	//get vector size
	while (getline(joltsList, line)) {
		totalLines++;
	}
	joltsList.close();
	
	//fill jolts vector with all nums
	joltsList.open("../day10input.txt", ios::in);
	while (getline(joltsList, line)) {
		currLine++;
		if (currLine <= (totalLines / 2)) {
			num = 0;
			stringstream lineNum(line);
			lineNum >> num;
			joltsVect1.push_back(num);
		}
		else if (currLine > (totalLines / 2)) {
			num = 0;
			stringstream lineNum(line);
			lineNum >> num;
			joltsVect2.push_back(num);
		}
	}
	joltsList.close();

	// sort the two halves
	sort(joltsVect1.begin(), joltsVect1.end());
	sort(joltsVect2.begin(), joltsVect2.end());

	// merge
	vector<int> joltsSort;
	merge(joltsVect1.begin(), joltsVect1.end(), joltsVect2.begin(), joltsVect2.end(), back_inserter(joltsSort));
	
	//add in the 3 jolts for the personal device
	int joltsVectSize = joltsSort.size();
	int lastJolt = joltsSort[joltsVectSize -1];
	int addIn;
	addIn = lastJolt + 3;
	joltsSort.push_back(addIn);
	joltsSort.insert(joltsSort.begin(), 0);

	//count up the number of 1 jolt differences and the number of 3 volt differences
	joltsVectSize = joltsSort.size();
	for (int i = 0; i < joltsVectSize - 1; i++) {
		if (joltsSort[i + 1] == joltsSort[i] + 1) {
			oneJolt++;
		}
		if (joltsSort[i + 1] == joltsSort[i] + 3) {
			threeJolt++;
		}
	}
	for (int i = 0; i < joltsVectSize; i++) {
		cout << joltsSort[i] << " ";
	}
	cout << "\n" << endl;
	//multiply the 1 jolt and 3 jolt difference numbers and output the product
	product = oneJolt * threeJolt;

	cout << oneJolt << " " << threeJolt << endl;
	cout << product << endl;

	return 0;
}

