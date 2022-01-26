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
    
    
   
    
    void generate(vector<string>& chess,vector<vector<string>>& result,int col,int& n){
        
        if(col==n){
            result.push_back(chess);
            return;
        }
    
        
        for(int i=0;i<n;i++){
            if(! issafe(chess,i,col,n)){
            
    
            chess[i][col]='Q';
            generate(chess,result,col+1,n);
            chess[i][col]='.';
            
            
