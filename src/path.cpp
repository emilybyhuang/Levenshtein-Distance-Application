#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int path(vector<vector<int> > matrix) {
    vector<string> original;
    vector<string> desired;
    int i = original.size();
    int j = desired.size();
    string command;
    string commandString;

    while (i != 0 && j != 0) {
        int currentValue;
//        int index;
//        int indexneedreplace;
        currentValue = matrix[i][j];
        stringstream ss;
        ss << j;
        string strOne = ss.str();
            int topleftValue = matrix[i-1][j-1];
            int leftValue = matrix[i][j-1];
            int topValue = matrix[i-1][j];
            if (topleftValue <= leftValue && topleftValue <= topValue) {//the top left is the smallest
                if (topleftValue < currentValue) {
                    int replaceValue = matrix[i][0];
                    stringstream myreplaceValue;
                    myreplaceValue << replaceValue;
                    string strTwo = myreplaceValue.str();
                    command = "Replace " + strOne + ", "+ strTwo + "\n";
                    commandString = commandString + command;
                } else if (topleftValue == currentValue) {
                   //equal
                   //do nothing to the output file
                }
            }
            if (topValue <= topleftValue && topValue <= leftValue){//the top one is the smallest
                command = "Delete " + strOne + "\n";
                commandString = commandString + command;
            }
            if (leftValue <= topleftValue && leftValue <= topValue){//the left one is the smallest
                command = "Insert " + strOne + "\n";
                commandString = commandString + command;
            }
            j = j-1;
            i = i-1;
    }
    while(i != 0 | j != 0){
        stringstream ss;
        ss << j;
        string strOne = ss.str();
        if(i == 0){// the only path is to the left
            command = "Insert " + strOne + "\n";
            commandString = commandString + command;
            j = j - 1;
        }
        else if(j == 0){// the only path is to the right
            command = "Delete " + strOne + "\n";
            commandString = commandString + command;
            i = i - 1;
        }
    }
    ofstream outputFile;
    outputFile.open("outputFile.out");
    outputFile << commandString;
    outputFile.close();
}

