#include<iostream>
#include<vector>

#define N 9
#define UNASSIGNED 0
using namespace std;


/* A utility function to print grid  */
void printGrid(int grid[N][N]);

// This function finds an entry in grid that is still unassigned
bool FindUnassignedLocation(int grid[N][N], int &row, int &col);

/* Takes a partially filled-in grid and attempts to assign values to
  all unassigned locations in such a way to meet the requirements
  for Sudoku solution (non-duplication across rows, columns, and boxes) */
bool SolveSudoku(int grid[N][N]);

// Checks whether it will be legal to assign num to the given row,col
bool isSafe(int grid[N][N], int row, int col, int num);

/* Returns a boolean which indicates whether any assigned entry
   in the specified row matches the given number. */
bool UsedInRow(int grid[N][N], int row, int num);

/* Returns a boolean which indicates whether any assigned entry
   in the specified column matches the given number. */
bool UsedInCol(int grid[N][N], int col, int num);

/* Returns a boolean which indicates whether any assigned entry
   within the specified 3x3 box matches the given number. */
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num);

int main()
{
    // 0 means unassigned cells
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (SolveSudoku(grid) == true)
          printGrid(grid);
    else
         cout<<"No solution exists.\n";

    return 0;
}

bool SolveSudoku(int grid[N][N]){

    int row;
    int col;
    while(FindUnassignedLocation(grid, row, col)){

        for(int num=1; num<=N; num++) {
            if( isSafe(grid, row, col, num)){
                grid[row][col] = num;
                if( SolveSudoku(grid))
                    return true;
                grid[row][col] = UNASSIGNED; // BACKTRACKING : redo your past UNASSIGNED
            }
        }//ROF
        return false;
    }//ELIHW
    return true;
}

//bool SolveSudoku(int grid[N][N]){
//
//    int row ;
//    int col ;
//    if(!FindUnassignedLocation(grid, row, col)){
//        return true;
//    }
//
//    for(int num=1; num<=N; num++) {
//        if( isSafe(grid, row, col, num) ){
//            grid[row][col] = num;
//            if( SolveSudoku(grid))
//                return true;
//            grid[row][col] = UNASSIGNED; // BACKTRACKING : redo your past UNASSIGNED
//        }
//    }
//    return false;
//}

bool FindUnassignedLocation(int grid[N][N], int &row, int &col){
    for(row=0; row<N; row++){
        for(col=0; col<N; col++){
            if(grid[row][col]==UNASSIGNED){
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int num){

    return ( !UsedInRow(grid, row, num) &&
             !UsedInCol(grid, col, num) &&
             !UsedInBox(grid, row - row%3, col-col%3, num));
}

bool UsedInRow(int grid[N][N], int row, int num){
    for(int i=0; i<N; i++){
        if(grid[row][i] == num)
            return true;
    }
    return false;
}

bool UsedInCol(int grid[N][N], int col, int num){
    for(int i=0; i<N; i++){
        if(grid[i][col] == num)
            return true;
    }
    return false;
}

bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num){
    for(int i=boxStartRow; i<boxStartRow+3; i++){
        for(int j=boxStartCol; j<boxStartCol+3; j++){
            if(grid[i][j] == num)
                return true;
        }
    }
    return false;
}

void printGrid(int grid[N][N]){
    for(int i= 0; i<N; i++){
        for(int j= 0; j<N; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}


