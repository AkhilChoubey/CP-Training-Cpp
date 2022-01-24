#include<bits/stdc++.h>
using namespace std;

int xMoves[4] = {0 , 0, 1, -1};
int yMoves[4] = {1, -1, 0 , 0};

bool isSafe(vector<vector<char>> &board,vector<vector<bool>> &visited, string &word, int index, int x, int y, const int &R,const int &C){
    return (x >=0 && x < R && y >=0 && y < C && !visited[x][y] && board[x][y] == word[index]);
}

bool wordExistHelper(vector<vector<char>> &board,vector<vector<bool>> &visited, string &word, int index, int x, int y, const int &R,const int &C){
    //base conditions
   if(index >= word.size()){
       return true;
   }
   else {
           //recursion
        visited[x][y] = true;
        for(int i = 0; i < 4; i++){
            int nextX = x + xMoves[i];
            int nextY = y + yMoves[i];
            if(isSafe(board, visited, word, index, nextX, nextY, R, C)){   
                if(wordExistHelper(board, visited, word, index + 1, nextX, nextY, R, C)){
                    return true;
                }
            }
        }

        //backtraking
        visited[x][y] = false;
        return false;
   }
   return false;


}

bool wordExist(vector<vector<char>> &board, string word){
    if(word == "") {
        return true;
    }
    int R = board.size();
    if(R == 0){
        return false;
    }
    int C = board[0].size();

    vector<vector<bool>> visited(R, vector<bool>(C, false));

      for(int i = 0; i<R; i++){
        for(int j =0; j<C; j++){
            if( board[i][j] == word[0] && wordExistHelper(board, visited, word, 1, i, j, R, C)){
                return true;
            }
        }
    }
    return false;
    
}

int main(){

}
