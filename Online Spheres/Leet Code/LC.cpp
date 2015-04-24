#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> output;
    // two boolean can define 2*2 = 4 directions
    bool goRight = true;
    bool goDown = true;

    int i = 0;
    int j = 0;
    int k = 1;

    int ROW = matrix.size();
    if(!ROW) return output;
    int COL = matrix[0].size();
    if(ROW ==1){
        return matrix[0];
    }

    int row_min = 1;
    int row_max = ROW;

    int col_min = 0;
    int col_max = COL;

    output.push_back(matrix[i][j]);
    cout<<"*"<<matrix[i][j]<<"-";
    while(k <= ROW*COL-1 )
    {
        // ---->
        if(COL==1) goRight = false;
        if(goRight && goDown){
            cout<<endl<<"\ncol_max ="<<col_max<<endl;
            while(j+1 < col_max){
                j++;
                cout<<"*"<<matrix[i][j]<<"-";
                output.push_back(matrix[i][j]);
                k++;
            }
            goRight = false; // right = !right;
            col_max--;
        }
        // DOWN
        if(goDown && !goRight){
            cout<<endl<<"\nrow_max ="<<row_max<<endl;
            while(i+1 < row_max){
                i++;
                cout<<"*"<<matrix[i][j]<<"-";
                output.push_back(matrix[i][j]);
                k++;
            }
            goDown = false; // down = !down;
            row_max--;
        }
        // <----
        if(COL==1) goDown = true;
        if(!goRight && !goDown && k <= ROW*COL-1 ){
            cout<<endl<<"\ncol_min ="<<col_min<<endl;
            while(j > col_min ){
                j--;
                cout<<"*"<<matrix[i][j]<<"-";
                output.push_back(matrix[i][j]);
                k++;
            }
            goRight = true; // right = !right;
            col_min++;
        }
        // UP
        if(!goDown && goRight){
            cout<<endl<<"\nrow_min ="<<row_min<<endl;
            while(i >row_min ){
                i--;
                cout<<"*"<<matrix[i][j]<<"-";
                output.push_back(matrix[i][j]);
                k++;
            }
            goDown = true; // down = !down;
            row_min++;
        }
    }
    return output;
}

int main() {
	int RR =2;
	int CC =2;
	;
	vector<vector<int> > matrix(RR);
	for ( int i = 0 ; i < RR ; i++ )
   		matrix[i].resize(CC);
   	cout<<"Input :\n";
   	int p=1;
   	for(int i = 0; i<RR; i++) {
    	for(int j = 0; j<CC; j++) {
         	matrix[i][j] = p++;
         	cout<<matrix[i][j]<<" ";
    	}
    	cout<<endl;
	}
	vector<int> result = spiralOrder(matrix);
	for(int i =0; i<result.size(); i++){
        cout<<result[i]<<", ";
	}
	return 0;
}

