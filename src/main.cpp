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
	cout << "old" << endl;
	while(file.peek() != '\n' && !file.eof()){
		file >> letter; 
		cout << "inserting bookauthor: " << letter << endl;
		original.push_back(letter);
				
	}
	cout << "new" << endl;
	while(!file.eof()){
		file >> letter;
		cout << "inserting bookauthor: " << letter << endl;
		desired.push_back(letter);
		
	}
	vector<vector<int> > newmatrix = matrix(original, desired);		
	return path(newmatrix);
}