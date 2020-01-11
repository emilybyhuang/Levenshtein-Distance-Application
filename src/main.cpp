#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <path.h>
#include <matrix.h>

using namespace std;

int main(int argc, char *argv[]) {
	string command, line;
	char letter;
	vector<char> original;
	vector<char> desired;
	int index1 = 0, index2 = 0;
	fstream file(argv[1]);
	if (!file.is_open()) cout<< "Could not open file\n";
	//while(!file.eof()){
	//cout << "old" << endl;
	while(((file.peek() >= 65 && file.peek()<=90) || (file.peek() >= 97 && file.peek()<=122 ))&& !file.eof()){
		file >> letter; 
		cout << "inserting bookauthor: " << letter << endl;
		original.push_back(letter);
		if(file.peek() == '\n') break;
	}
	cout << "new" << endl;
	while(!file.eof()){
		file >> letter;
		cout << "inserting bookauthor: " << letter << endl;
		desired.push_back(letter);
		if(file.peek() == '\n') break;
	}
	vector<vector<int> > newmatrix = matrix(original, desired);	
	string commandString = path(newmatrix, original, desired);
	ofstream outputFile(argv[2]);
    //outputFile.open(argv[2]);
    outputFile << commandString;
    outputFile.close();
}