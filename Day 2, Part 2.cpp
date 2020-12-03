#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getInt(string num);
bool isValid(int posOne, int posTwo, char keyChar, string password);

int main()
{
    string line, range1, range2, password, ins0;
    int rangePt1, rangePt2, validCount;
    char keyLetter;
    bool validPass;

    ins0 = "0";
    validCount = 0;

    //get the file
    ifstream passwordFile;
    passwordFile.open("../input.txt", ios::in);

    //read in each line and break out the 3 parts: range, letter, and password
    while (getline(passwordFile, line)) {
        password = "";
        range1 = "";
        range2 = "";
        if (line[1] == '-')
            line.insert(0, ins0);
        if (line[4] == ' ')
            line.insert(3, ins0);
        range1.append(line, 0, 2);
        range2.append(line, 3, 2);
        keyLetter = line[6];
        password.append(line, 9, line.length() - 1);

        //get range start and stop as ints
        rangePt1 = getInt(range1);
        rangePt2 = getInt(range2);

        validPass = isValid(rangePt1, rangePt2, keyLetter, password);

        if (validPass == true)
            validCount++;
    }

    cout << validCount << endl;

    return 0;
}

//function to identify if it meets the conditions (args: len range, letter, password)
// for pword iterate from i = 9-end

//function to change # chars to integers
// pull in each char 1 at a time and use to assign a variable an integer and return the integer
int getInt(string num) {
    int tens, ones, retVal;
    tens = 0;
    ones = 0;
    retVal = 0;
    //get tens place if needed
    if (num[0] == '1')
        tens = 10;
    else if (num[0] == '2')
        tens = 20;
    else if (num[0] == '3')
        tens = 30;
    else if (num[0] == '4')
        tens = 40;

    //get ones place
    if (num[1] == '0')
        ones = 0;
    else if (num[1] == '1')
        ones = 1;
    else if (num[1] == '2')
        ones = 2;
    else if (num[1] == '3')
        ones = 3;
    else if (num[1] == '4')
        ones = 4;
    else if (num[1] == '5')
        ones = 5;
    else if (num[1] == '6')
        ones = 6;
    else if (num[1] == '7')
        ones = 7;
    else if (num[1] == '8')
        ones = 8;
    else if (num[1] == '9')
        ones = 9;

    //add them for return int
    retVal = tens + ones;

    return retVal;
}

bool isValid(int posOne, int posTwo, char keyChar, string password) {
    int index1, index2;
    index1 = posOne - 1;
    index2 = posTwo - 1; 
    if ((password[index1] == keyChar && password[index2] != keyChar) || (password[index1] != keyChar && password[index2] == keyChar)) {
        return true;
    }
    else {
        return false;
    }

}