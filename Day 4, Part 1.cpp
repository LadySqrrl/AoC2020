#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool hasBYR(string info, int infoLength);
bool hasIYR(string info, int infoLength);
bool hasEYR(string info, int infoLength);
bool hasHGT(string info, int infoLength);
bool hasHCL(string info, int infoLength);
bool hasECL(string info, int infoLength);
bool hasPID(string info, int infoLength);
bool isValid(string info, int infoLength);

int main()
{
    string line;
    string fullInfo;
    int validTotal, infoLen;
    bool isValidPass;
    validTotal = 0;
    infoLen = 0;
    isValidPass = false;

    //get the file
    ifstream passportInfo;
    passportInfo.open("../input.txt", ios::in);

    //break out each full passport's info into one string to parse
    while (getline(passportInfo, line)) {
        //if not at a blank line, add the info into the full info string
        if (line.length() != 0) {
            fullInfo.append(line, 0, line.length());
        }
        //if you hit a blank line, check the full info you've got to see if it's valid then reset fullInfo string
        else {
            infoLen = fullInfo.length();
            isValidPass = isValid(fullInfo, infoLen);
            if (isValidPass == true) {
                validTotal++;
            }
            fullInfo = "";
        }
    }

    cout << validTotal << endl;
    return 0;
}


//is the birth year in there?
bool hasBYR(string info, int infoLength) {
    string currInfo;
    bool found = false;
    int searchLen;
    searchLen = infoLength - 4;
    currInfo = info;
    for (int i = 0; i < searchLen; i++) {
        if (currInfo[i] == 'b' && currInfo[i + 1] == 'y' && currInfo[i + 2] == 'r' && currInfo[i + 3] == ':') {
            found = true;
        }
    }
    if (found == true)
        return true;
    else
        return false;
}

//is the issue yera in there?
bool hasIYR(string info, int infoLength) {
    string currInfo;
    bool found = false;
    int searchLen;
    searchLen = infoLength - 4;
    currInfo = info;
    for (int i = 0; i < searchLen; i++) {
        if (currInfo[i] == 'i' && currInfo[i + 1] == 'y' && currInfo[i + 2] == 'r' && currInfo[i + 3] == ':') {
            found = true;
        }
    }
    if (found == true)
        return true;
    else
        return false;
}

//is the expiration yera in there?
bool hasEYR(string info, int infoLength) {
    string currInfo;
    bool found = false;
    int searchLen;
    searchLen = infoLength - 4;
    currInfo = info;
    for (int i = 0; i < searchLen; i++) {
        if (currInfo[i] == 'e' && currInfo[i + 1] == 'y' && currInfo[i + 2] == 'r' && currInfo[i + 3] == ':') {
            found = true;
        }
    }
    if (found == true)
        return true;
    else
        return false;
}

//is the height in there?
bool hasHGT(string info, int infoLength) {
    string currInfo;
    bool found = false;
    int searchLen;
    searchLen = infoLength - 4;
    currInfo = info;
    for (int i = 0; i < searchLen; i++) {
        if (currInfo[i] == 'h' && currInfo[i + 1] == 'g' && currInfo[i + 2] == 't' && currInfo[i + 3] == ':') {
            found = true;
        }
    }
    if (found == true)
        return true;
    else
        return false;
}

// is the hair color there?
bool hasHCL(string info, int infoLength) {
    string currInfo;
    bool found = false;
    int searchLen;
    searchLen = infoLength - 4;
    currInfo = info;
    for (int i = 0; i < searchLen; i++) {
        if (currInfo[i] == 'h' && currInfo[i + 1] == 'c' && currInfo[i + 2] == 'l' && currInfo[i + 3] == ':') {
            found = true;
        }
    }
    if (found == true)
        return true;
    else
        return false;
}

//is eye color there?
bool hasECL(string info, int infoLength) {
    string currInfo;
    bool found = false;
    int searchLen;
    searchLen = infoLength - 4;
    currInfo = info;
    for (int i = 0; i < searchLen; i++) {
        if (currInfo[i] == 'e' && currInfo[i + 1] == 'c' && currInfo[i + 2] == 'l' && currInfo[i + 3] == ':') {
            found = true;
        }
    }
    if (found == true)
        return true;
    else
        return false;
}

//is passport ID there?
bool hasPID(string info, int infoLength) {
    string currInfo;
    bool found = false;
    int searchLen;
    searchLen = infoLength - 4;
    currInfo = info;
    for (int i = 0; i < searchLen; i++) {
        if (currInfo[i] == 'p' && currInfo[i + 1] == 'i' && currInfo[i + 2] == 'd' && currInfo[i + 3] == ':') {
            found = true;
        }
    }
    if (found == true)
        return true;
    else
        return false;
}

//is the passport valid? (byr, iyr, hgt, hcl, ecl, pid all return true)
bool isValid(string info, int infoLength) {
    bool byr, iyr, eyr, hgt, hcl, ecl, pid;
    byr = hasBYR(info, infoLength);
    iyr = hasIYR(info, infoLength);
    eyr = hasEYR(info, infoLength);
    hgt = hasHGT(info, infoLength);
    hcl = hasHCL(info, infoLength);
    ecl = hasECL(info, infoLength);
    pid = hasPID(info, infoLength);

    if (byr == true && iyr == true && eyr == true && hgt == true && hcl == true && ecl == true && pid == true) {
        return true;
    }
    else {
        return false;
    }
}