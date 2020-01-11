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
	//2 vectors: one for original one for desired
	vector<char> original;
	vector<char> desired;
	//read from the input file
	fstream file(argv[1]);

	//check the input file
	if (!file.is_open()) cout<< "Could not open file\n";
	//cout << "old" << endl;

	//make 1st vector
	//continue to looop if it's not end of file or next character is a part of the alphabet
	while(((file.peek() >= 65 && file.peek()<=90) || (file.peek() >= 97 && file.peek()<=122 ))&& !file.eof()){
		file >> letter; 
		//cout << "letter: " << letter << endl;
		original.push_back(letter);
		if(file.peek() == '\n') break;
	}

	//make 2nd vector
	//cout << "new" << endl;
	while(!file.eof()){
		file >> letter;
		//cout << "letter: " << letter << endl;
		desired.push_back(letter);
		if(file.peek() == '\n') break;
	}

	//make a maxtrix using evenshtein distance method
	vector<vector<int> > newmatrix = matrix(original, desired);	
	string commandString = path(newmatrix, original, desired);
	//make an output string for the moves needed
	ofstream outputFile(argv[2]);
    outputFile << commandString;
    outputFile.close();
}