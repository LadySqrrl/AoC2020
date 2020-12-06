#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void sortString(string& str)
{
	sort(str.begin(), str.end());
}
int getGroupCount(string line, int groupSize);

int main()
{
	string line;
	string groupAns = "";
	int groupAnsCount, totalAns, groupSize;
	groupAnsCount = 0;
	totalAns = 0;
	groupSize = 0;

	ifstream customsInfo;
	customsInfo.open("../input.txt", ios::in);

	while (getline(customsInfo, line)) {
		//group all group answers into one line if not, blank, append. count lines (group members)
		if (line.length() != 0) {
			groupAns.append(line, 0, line.length());
			groupSize++;
		}
		//if blank, do operations on the group data you have collected adn get a group # and add to total
		else {
			groupAnsCount = getGroupCount(groupAns, groupSize);
			totalAns += groupAnsCount;
			groupSize = 0;
			groupAnsCount = 0;
			groupAns = "";
		}
	}

	cout << totalAns << endl;

	return 0;
}

int getGroupCount(string line, int groupSize) {
	int letterCount, ansCount;
	letterCount = 0;
	ansCount = 0;
	//do each letter seeing if everyone answered it yes
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'a') {
			letterCount++;
		}

	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'b') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'c') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'd') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'e') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'f') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'g') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'h') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'i') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'j') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'k') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'l') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'm') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'n') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'o') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'p') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'q') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'r') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 's') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 't') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'u') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'v') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'w') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'x') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'y') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}
	letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'z') {
			letterCount++;
		}
	}
	if (letterCount == groupSize) {
		ansCount++;
	}

	return ansCount;

	}
