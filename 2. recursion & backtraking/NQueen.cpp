#include<bits/stdc++.h >
using namespace std;

    bool issafe(vector<string>& chessboard,int& x,int& y,int& n){
        
       //row me nhi
        for(int i=0;i<y;i++)
            if( chessboard[x][i]=='Q')
                return true;
        
        //upper diagnol me nhi
        for(int k=x-1,j=y-1;k>=0 and j>=0;k--,j--)
            if(chessboard[k][j]=='Q')
                return true;
        
        // lower diagonal me ni
        for(int k=x+1,j=y-1;k<n and j>-1;k++,j--)
            if(chessboard[k][j]=='Q')
                return true;
        
        return false;
    }
    
    
   
    
    // void generate(vector<string>& chess,vector<vector<string>>& result,int col,int& n){
        
    //     if(col==n){
    //         result.push_back(chess);
    //         return;
    //     }
    
        
    //     for(int i=0;i<n;i++){
    //         if(! issafe(chess,i,col,n)){
            
    
    //         chess[i][col]='Q';
    //         generate(chess,result,col+1,n);
    //         chess[i][col]='.';
            
            



    // bool isSafe(vector<vector<string>> &solvedMatrix,int x,int y,int n){
    //     for(int i = 0; i < y ; i++){
    //         if(solvedMatrix[x][i] == "Q"){
    //             return false;
    //         }
    //     }
    //     int row = x;
    //     int col = y;
    //     while(row >= 0 && col >= 0){
    //         if(solvedMatrix[row][col] == "Q"){
    //             return false;
    //         }
    //         --row;
    //         --col;
    //     }
    //     row = x;
    //     col = y;
    //     while(row < n && col >= 0){
    //         if(solvedMatrix[row][col] == "Q"){
    //             return false;
    //         }
    //         ++row;
    //         --col;
    //     }
    //     return true;
    // }
    // vector<vector<string>> finalAns;
    // bool findTheSolution(vector<vector<string>> &solvedMatrix,int col,int n){
    //     if(col >= n){
    //         vector<string> temp;
    //         for(auto ele: solvedMatrix){
    //             string s = "";
    //             for(auto i : ele){
    //                 s += i;
    //             }
    //             temp.push_back(s);
    //         }
    //         finalAns.push_back(temp);
    //         return true;
    //     }
        
    //     for(int i=0;i<n;i++){
    //         if(isSafe(solvedMatrix,i,col,n)){
    //             solvedMatrix[i][col] = "Q";
    //             if(findTheSolution(solvedMatrix,col+1,n)){
    //                 continue;
    //             }
    //             solvedMatrix[i][col] = ".";
    //         }
    //     }
    //     return false;
    // }
    // vector<vector<string>> solveNQueens(int n) {
    //     vector<vector<string>> solvedMatrix(n,vector<string>(n,"."));
    //     findTheSolution(solvedMatrix,0,n);
    //     return finalAns;
    // }