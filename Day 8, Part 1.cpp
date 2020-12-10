#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


//PLAN:
//if "nop" just move to next line
//if "acc", increment accumulator by number listed
//if "jmp", jump to that line in the list
	//set a "jump" integer?
//figure out how to count lines and what line i'm using
//set the count of what line to go to as current line += jump integer
//go through and complete each applicable operation


int main()
{
	ifstream instructions;
	string line;
	string jmpNum = "";
	string accNum = "";
	int accumulator, currLine, targetLine;
	vector<int> linesVisited = {1};
	currLine = 0;
	targetLine = 1;
	accumulator = 0;
	bool repeats = false;

	//do this as long as the target line is not in the visited vector
	while (repeats == false) {
		instructions.open("../input.txt", ios::in);
		while (getline(instructions, line)) {
			//increment current line counter each time you move to the next line
			currLine++;
			//if we are on the correct line (target based on actions of previous round), find next target
			if (currLine == targetLine) {
				//look for what operation do do and exectue
				//if nop is found, increment the target line (move to the next line)
				size_t foundnop = line.find("nop");
				if (foundnop != string::npos) {
					targetLine++;
				}
				//if nop is not found, see if acc is found and if so, increment accumulator and target line
				else {
					size_t foundacc = line.find("acc");
					if (foundacc != string::npos) {
						accNum.append(line, 5);
						int accIter = 0;
						stringstream acc(accNum);
						acc >> accIter;
						//increemnt accumulator based on if going + or -
						if (line[4] == '+') {
							accumulator += accIter;
						}
						else if (line[4] == '-') {
							accumulator -= accIter;
						}
						else
							cout << "acc error" << endl;
						targetLine++;
						accNum = "";
					}
					//if neither nop nor acc are found in the line, look or jmp and set what line to jump to
					else {
						size_t foundjmp = line.find("jmp");
						if (foundjmp != string::npos) {
							jmpNum.append(line, 5);
							int jmpCount = 0;
							stringstream jmp(jmpNum);
							jmp >> jmpCount;
							//update target based on jmp and if going + or -
							if (line[4] == '+') {
								targetLine += jmpCount;
							}
							else if (line[4] == '-') {
								targetLine -= jmpCount;
							}
							else
								cout << "jmp error" << endl;
							jmpNum = "";
						}
					}
				}

				//close the file and reset current line to start search over 
				instructions.close();
				if (find(linesVisited.begin(), linesVisited.end(), targetLine) != linesVisited.end()) {
					repeats = true;
				}
				else {
					repeats = false;
					linesVisited.push_back(targetLine);
				}
				currLine = 0;
			}
		}
	}
	cout << accumulator << endl;
	return 0;
}
