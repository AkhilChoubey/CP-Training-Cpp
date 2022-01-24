#include<bits/stdc++.h>
#define SIZE 9
using namespace std;

 bool isEmpty(vector<vector<char>> &sudoku, int &row, int &col) {
    for(row = 0; row < SIZE; row++){
        for(col = 0; col < SIZE; col++){
            if(sudoku[row][col] == '.') {
                return true;
            }
        }
    }
    return false;
}

//Checking if element is present in that Row
bool usedInRow(vector<vector<char>> &sudoku, const int row, int fill) {
    for(int j = 0; j < SIZE; j++){
        if(sudoku[row][j] == fill) {
            return true;
        }
    }
    return false;
}

//Checking if element is present in that Row
bool usedInCol(vector<vector<char>> &sudoku, const int col, int fill) {
      for(int i = 0; i < SIZE; i++){
        if(sudoku[i][col] == fill) {
            return true;
        }
    }
    return false;
}

//Checking if element is present in that Row
bool usedInBox(vector<vector<char>> &sudoku, int row, int col, int fill) {

    row = row - row % 3;
    col = col - col % 3;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(sudoku[i + row][j + col] == fill) {
                return true;
            }
        }
       
    }
     return false;
}

bool isSafe(vector<vector<char>> &sudoku, const int row, const int col, int fill){

    // check if element already used in Row using usedInRow()
    // check if element already used in Column using usedInCol()
    // check if element already used in Box using usedInBox()

    return (!usedInRow(sudoku, row, fill) && !usedInCol(sudoku, col, fill) && !usedInBox(sudoku, row, col, fill));
}

void solveSudoku(vector<vector<char>> &sudoku) {
    int row, col; //empty cell location
    if(!isEmpty(sudoku, row, col)){
        return;
    }

     for(int i = 1; i <= 9; i++){
         if(isSafe(sudoku, row, col, i)) {
             sudoku[row][col] = i;
             solveSudoku(sudoku);

             //backtracking
             sudoku[row][col] = '.';
         }
     }
    

}


int main(){
    vector<vector<char>> sudoku = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]];

    solveSudoku(sudoku);
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j< SIZE; j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
}