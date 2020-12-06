#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void sortString(string& str)
{
	sort(str.begin(), str.end());
}
	
int main()
{
	string line;
	string groupAns = "";
	int groupAnsCount, totalAns;
	groupAnsCount = 0;
	totalAns = 0;

	ifstream customsInfo;
	customsInfo.open("../input.txt", ios::in);

	while (getline(customsInfo, line)) {
		//group all group answers into one line if not, blank, append
		if (line.length() != 0) {
			groupAns.append(line, 0, line.length());
		}
		//if blank, do operations on the group data you have collected
		else {
			groupAnsCount = 1;
			sortString(groupAns);
			for (int i = 0; i < groupAns.length()-1; i++) {
				if (groupAns[i] != groupAns[i + 1]) {
					groupAnsCount++;
				}
			}
			totalAns += groupAnsCount;
			groupAns = "";
		}
	}

	cout << totalAns << endl;

	return 0;
}
