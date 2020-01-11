/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <matrix.h>
using namespace std;

vector<vector<int> > matrix(vector <char> original, vector <char> desired){
    //cout << "in matrix" << endl;
    vector<vector<int> > matrix;
    vector<int> zerorow;
    for (auto i = 0; i <= desired.size(); i++) {
        zerorow.push_back(i);
    }
    matrix.push_back(zerorow);
    for (auto i = 1; i <= original.size(); i++) {
        vector<int> row;
        row.push_back(i);
        for (auto j = 1; j <= desired.size(); j++) {
            int cost = (original[i-1] == desired[j-1]) ? 0 : 1;
            int src1 = matrix[i-1][j] + 1;
            int src2 = row[j-1] + 1;
            int src3 = matrix[i-1][j-1] + cost;
            row.push_back(min(min(src1, src2), src3));
        }
        matrix.push_back(row);
    }
    for (int i = 0; i <= original.size(); i++ ){
        for(int j = 0; j <= desired.size(); j++){
            cout << matrix[i][j] << " ";
            if(j == desired.size()) cout<<endl;
        }
        cout << endl;
    }
    return matrix;
    
}
