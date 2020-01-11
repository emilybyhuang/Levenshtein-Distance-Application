#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

string path(vector<vector<int> > matrix, vector<char> original,
    vector<char> desired) {
    //cout << "in path" << endl;
    int i = original.size();
    int j = desired.size();
    string command;
    string commandString;

    while (i != 0 && j != 0) {
        int currentValue;
//        int index;
//        int indexneedreplace;
        currentValue = matrix[i][j];
        stringstream ssOne;
        ssOne << j-1;
        string strOne = ssOne.str();
        stringstream ssTwo;
        ssTwo << j;
        string strTwo = ssTwo.str();
            int topleftValue = matrix[i-1][j-1];
            int leftValue = matrix[i][j-1];
            int topValue = matrix[i-1][j];
            if (topleftValue <= leftValue && topleftValue <= topValue) {//the top left is the smallest
                if (topleftValue < currentValue) {
                    int replaceValue = matrix[i][0];
                    //stringstream myreplaceValue;
                    //myreplaceValue << replaceValue;
                    //string strTwo = myreplaceValue.str();
                    command = "Replace " + strOne + ", "+ "'" + desired[j - 1]+ "'" + "\n";
                    commandString = command + commandString;
                } else if (topleftValue == currentValue) {
                   //equal
                   //do nothing to the output file
                }
                i --;
                j --;
            }
            else if (topValue <= topleftValue && topValue <= leftValue){//the top one is the smallest
                command = "Delete " + strTwo + "\n";
                commandString = command + commandString;
                i--;
            }
            else if (leftValue <= topleftValue && leftValue <= topValue){//the left one is the smallest
                command = "Insert " + strOne + "\n";
                commandString = command + commandString;
                j--;
            }
            
    }
    while(i != 0 | j != 0){
        stringstream ss;
        ss << j;
        string strOne = ss.str();
        if(i == 0){// the only path is to the left
            command = "Insert " + strOne + "\n";
            commandString = command + commandString;
            j = j - 1;
        }
        else if(j == 0){// the only path is to the right
            command = "Delete " + strOne + "\n";
            commandString = command + commandString;
            i = i - 1;
        }
    }
    return commandString;
    // ofstream outputFile;
    // outputFile.open("outputFile.out");
    // outputFile << commandString;
    // outputFile.close();
}

