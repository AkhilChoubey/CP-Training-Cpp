#include <bits/stdc++.h>
#define N 8
using namespace std;

bool isSafe( int nextX, int nextY, vector<vector<int> > &solution){
    return (nextX >=0 && nextX < N && nextY >=0 && nextY < N && solution[nextX][nextY] == -1);
}
int xMoves[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int yMoves[8] = {1, 2, 2, 1, -1, -2, -2, -1};


int solveKnightHelper( int countDone,vector<vector<int> > &solution, int row, int col){
    //base
    if(countDone == N*N) {
        return 1;
    }


    //reccursion
    for(int i=0;i<N;i++){
        int nextX = row + xMoves[i];
        int nextY = col + yMoves[i];

        
        if(isSafe(nextX, nextY, solution)){
            solution[nextX][nextY] = countDone;
             if(solveKnightHelper( countDone + 1, solution, nextX, nextY) == 1) {
                 return 1;
             } 
             else {
            solution[nextX][nextY] = -1;
             } 
        }     
         
    }
    return 0;
}

void solveKnightChess(vector<vector<int> > &solution) {
    solution[0][0] = 0;
    if(solveKnightHelper( 1, solution , 0, 0) == 1){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<solution[i][j]<<" ";
            }
            cout<<"\n";

        }
        return;
    }
    else {
        cout<<"Path not found"<<endl;
        return;
    }
    
}


int main() {
    // int x, y;
    // cin>>x>>y;
  
  vector<vector<int> > solution(N, vector<int>(N, -1));
  solveKnightChess(solution);

  
}
