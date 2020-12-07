#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

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
            fullInfo.append(" ");
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


//is the birth year in there? is it valid? 1920-2002
bool hasBYR(string info, int infoLength) {
    string currInfo;
    string data;
    bool found = false;
    bool validBYR = false;
    int searchLen, byr;
    searchLen = infoLength - 8;
    currInfo = info;
    for (int i = 0; i < searchLen; i++) {
        if (currInfo[i] == 'b' && currInfo[i + 1] == 'y' && currInfo[i + 2] == 'r' && currInfo[i + 3] == ':') {
            found = true;
            data.append(currInfo, i + 4, 4);
            //get as int
            stringstream byrInt(data);
            byrInt >> byr;
            //is it valid?
            if (byr > 1919 && byr < 2003) {
                validBYR = true;
            }
        }
    }
    if (found == true && validBYR == true)
        return true;
    else
        return false;
}

//is the issue year in there? is it valid? (2010-2020)
bool hasIYR(string info, int infoLength) {
    string currInfo;
    string data;
    bool found = false;
    bool validData = false;
    int searchLen, iyr;
    searchLen = infoLength - 8;
    currInfo = info;
    for (int i = 0; i < searchLen; i++) {
        if (currInfo[i] == 'i' && currInfo[i + 1] == 'y' && currInfo[i + 2] == 'r' && currInfo[i + 3] == ':') {
            found = true;
            data.append(currInfo, i + 4, 4);
            //get as int
            stringstream iyrInt(data);
            iyrInt >> iyr;
            //is it valid?
            if (iyr > 2009 && iyr < 2021) {
                validData = true;
            }
        }
    }
    if (found == true && validData == true)
        return true;
    else
        return false;
}

//is expiration there? is it valid? 2020-2030
bool hasEYR(string info, int infoLength) {
    string currInfo;
    string data;
    bool found = false;
    bool validData = false;
    int searchLen, eyr;
    searchLen = infoLength - 8;
    currInfo = info;
    for (int i = 0; i < searchLen; i++) {
        //is it there?
        if (currInfo[i] == 'e' && currInfo[i + 1] == 'y' && currInfo[i + 2] == 'r' && currInfo[i + 3] == ':') {
            found = true;
            data.append(currInfo, i + 4, 4);
            //get as int
            stringstream eyrInt(data);
            eyrInt >> eyr;
            //is valid?
            if (eyr > 2019 && eyr < 2031) {
                validData = true;
            }
        }
    }
    if (found == true && validData == true)
        return true;
    else
        return false;
}

//is the height in there? is it valid? 59-76in or 150-193cm
bool hasHGT(string info, int infoLength) {
    string currInfo;
    bool found = false;
    bool validHGT = false;
    int searchLen;
    searchLen = infoLength - 8;
    currInfo = info;
    for (int i = 0; i < searchLen; i++) {
        if (currInfo[i] == 'h' && currInfo[i + 1] == 'g' && currInfo[i + 2] == 't' && currInfo[i + 3] == ':') {
            found = true;

            if (i == searchLen - 1) {
                if (currInfo[i + 6] == 'i' && currInfo[i + 7] == 'n') {
                    if ((currInfo[i + 4] == 53 && currInfo[i + 5] == 57) || (currInfo[i + 4] == 54 && currInfo[i + 5] > 47 && currInfo[i + 5] < 58) || (currInfo[i + 4] == 55 && currInfo[i + 5] > 47 && currInfo[i + 5] < 55)) {
                        validHGT = true;
                    }
                }
            }
            else if (i < searchLen - 1) {
                if (currInfo[i + 6] == 'i' && currInfo[i + 7] == 'n') {
                    if ((currInfo[i + 4] == 53 && currInfo[i + 5] == 57) || (currInfo[i + 4] == 54 && currInfo[i + 5] > 47 && currInfo[i + 5] < 58) || (currInfo[i + 4] == 55 && currInfo[i + 5] > 47 && currInfo[i + 5] < 55)) {
                        validHGT = true;
                    }
                }
                else if (currInfo[i + 7] == 'c' && currInfo[i + 8] == 'm') {
                    if (currInfo[i + 4] == 49 && ((currInfo[i + 5] > 52 && currInfo[i + 5] < 57 && currInfo[i + 6] >47 && currInfo[i + 6] < 58) || (currInfo[i + 5] == 57 && currInfo[i + 6] > 47 && currInfo[i + 6] < 52))) {
                        validHGT = true;
                    }
                }
            }
        }
    }
    if (found == true && validHGT == true)
        return true;
    else
        return false;
}

// is the hair color there? is it valid? # and 3 digits and 3 letters a-f
bool hasHCL(string info, int infoLength) {
    string currInfo;
    string hcl;
    bool validHCL = false;
    bool found = false;
    bool partOne = false;
    bool partTwo = false;
    int searchLen;
    searchLen = infoLength - 11;
    currInfo = info;
    for (int i = 0; i < searchLen; i++) {
        if (currInfo[i] == 'h' && currInfo[i + 1] == 'c' && currInfo[i + 2] == 'l' && currInfo[i + 3] == ':') {
            found = true;
            if (i == searchLen - 1) {
                hcl.append(currInfo, i + 4, 7);
                if (hcl[0] == 35 && (((hcl[1] > 47 && hcl[1] < 58) || (hcl[1] > 96 && hcl[1] < 103)) && ((hcl[2] > 47 && hcl[2] < 58) || (hcl[2] > 96 && hcl[2] < 103)) && ((hcl[3] > 47 && hcl[3] < 58) || (hcl[3] > 96 && hcl[3] < 103)) && ((hcl[4] > 47 && hcl[4] < 58) || (hcl[4] > 96 && hcl[4] < 103)) && ((hcl[5] > 47 && hcl[5] < 58) || (hcl[5] > 96 && hcl[5] < 103)) && ((hcl[6] > 47 && hcl[6] < 58) || (hcl[6] > 96 && hcl[6] < 103)))) {
                    validHCL = true;
                }
            }
            else {
                hcl.append(currInfo, i + 4, 8);
                if (hcl[0] == 35 && hcl[7] == ' ' && (((hcl[1] > 47 && hcl[1] < 58) || (hcl[1] > 96 && hcl[1] < 103)) && ((hcl[2] > 47 && hcl[2] < 58) || (hcl[2] > 96 && hcl[2] < 103)) && ((hcl[3] > 47 && hcl[3] < 58) || (hcl[3] > 96 && hcl[3] < 103)) && ((hcl[4] > 47 && hcl[4] < 58) || (hcl[4] > 96 && hcl[4] < 103)) && ((hcl[5] > 47 && hcl[5] < 58) || (hcl[5] > 96 && hcl[5] < 103)) && ((hcl[6] > 47 && hcl[6] < 58) || (hcl[6] > 96 && hcl[6] < 103)))) {
                    validHCL = true;
                }
            }
        }
    }
    if (found == true && validHCL == true)
        return true;
    else
        return false;
}

//is eye color there? is it valid? amb, brn, blu, gry, grn, hzl, oth
bool hasECL(string info, int infoLength) {
    string currInfo;
    string ecl;
    bool found = false;
    bool validECL = false;
    int searchLen;
    searchLen = infoLength - 7;
    currInfo = info;
    for (int i = 0; i < searchLen; i++) {
        if (currInfo[i] == 'e' && currInfo[i + 1] == 'c' && currInfo[i + 2] == 'l' && currInfo[i + 3] == ':') {
            found = true;
            ecl.append(currInfo, i + 4, 3);
            if (ecl == "amb" || ecl == "blu" || ecl == "brn" || ecl == "gry" || ecl == "grn" || ecl == "hzl" || ecl == "oth")
                validECL = true;
        }
    }
    if (found == true && validECL == true)
        return true;
    else
        return false;
}

//is passport ID there? is it valid? 9 digits long including leading zeros
bool hasPID(string info, int infoLength) {
    string currInfo;
    bool found = false;
    bool validPID = false;
    int searchLen;
    searchLen = infoLength - 12;
    currInfo = info;
    for (int i = 0; i < searchLen; i++) {
        if (currInfo[i] == 'p' && currInfo[i + 1] == 'i' && currInfo[i + 2] == 'd' && currInfo[i + 3] == ':') {
            found = true;
            if (i == searchLen) {
                if (currInfo[i + 4] > 47 && currInfo[i + 4] < 58 && currInfo[i + 4] >47 && currInfo[i + 4] < 58 && currInfo[i + 5] >47 && currInfo[i + 5] < 58 && currInfo[i + 6] >47 && currInfo[i + 6] < 58 && currInfo[i + 7] >47 && currInfo[i + 7] < 58 && currInfo[i + 8] >47 && currInfo[i + 8] < 58 && currInfo[i + 9] >47 && currInfo[i + 9] < 58 && currInfo[i + 10] >47 && currInfo[i + 10] < 58 && currInfo[i + 11] >47 && currInfo[i + 11] < 58 && currInfo[i + 12] >47 && currInfo[i + 12] < 58) {
                    validPID = true;
                }
            }
            else if (i < searchLen) {
                if (currInfo[i + 4] > 47 && currInfo[i + 4] < 58 && currInfo[i + 4] >47 && currInfo[i + 4] < 58 && currInfo[i + 5] >47 && currInfo[i + 5] < 58 && currInfo[i + 6] >47 && currInfo[i + 6] < 58 && currInfo[i + 7] >47 && currInfo[i + 7] < 58 && currInfo[i + 8] >47 && currInfo[i + 8] < 58 && currInfo[i + 9] >47 && currInfo[i + 9] < 58 && currInfo[i + 10] >47 && currInfo[i + 10] < 58 && currInfo[i + 11] >47 && currInfo[i + 11] < 58 && currInfo[i + 12] >47 && currInfo[i + 12] < 58 && currInfo[i + 13] == ' ') {
                    validPID = true;
                }
            }
        }
    }
    if (found == true && validPID == true) {
        return true;
    }
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


