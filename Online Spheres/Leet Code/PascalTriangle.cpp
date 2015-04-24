#include<iostream>
#include<vector>

using namespace std;

vector<int> getNextRow(vector<vector<int> > matrix , int rowNum) {
    vector<int> nextRow;
//    cout<<"\nTesting "<<matrix[0][0]<<endl;
    for(int col=0; col<=rowNum; col++){
        if(col==0 || col==rowNum) {
            nextRow.push_back(1);
//            cout<<"\nadding"<<1<<endl;
        }else{
            nextRow.push_back(matrix[rowNum-1][col-1]+matrix[rowNum-1][col]);
        }

    }
    return nextRow;
}

vector<vector<int> > generate(int numRows) {
    vector<vector<int> > matrix;
        if(numRows == 0) return matrix;
    vector<int> firstRow(1,1);
    matrix.push_back(firstRow);
        if(numRows == 1) return matrix;
    for(int i =1; i<numRows; i++){
//        cout<<"\n*"<<i;
        matrix.push_back(getNextRow(matrix, i));
    }
    return matrix;
}

int main(){
    vector<vector<int> > matrix =  generate(5);
//    cout<<"\ntotal row ="<<matrix.size()<<endl;
    for(int i=0; i<matrix.size(); i++){
//        cout<<"\ntotal col in this row ="<<matrix[i].size()<<endl;
        for(int j=0; j<matrix[i].size(); j++){
            cout<<"+"<<matrix[i][j]<<"- ";
        }
        cout<<endl;
    }
    return 0;
}

