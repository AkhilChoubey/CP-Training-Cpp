
int dp[27][27][55];

int xMoves[8] = {-1,-1,1,1,-2,-2,2,2};
int yMoves[8] = {-2,2,2,-2,-1,1,-1,1};

int knightProbabilityHelper(int n, int move, int i, int j) {

    if(i < 0 || j < 0 || i >= n || j >= n) {
        return 0.0;
    }

    if(move == 0) {
        return 1.0;
    }

    if(dp[i][j][move] != -1) {
        return dp[i][j][move];
    }

    double ans = 0;
    for(int k = 0; k < 8; k++) {
        int x = i + xMoves[k];
        int y = j + yMoves[k];

        ans = ans + knightProbabilityHelper(n, move-1, x, y)/8.0;
    }

    dp[i][j][move] = ans;
    return ans;
}


double knightProbability(int n, int k, int row, int column) {
    for(int i = 0; i < 27; i++) {
         for(int j = 0; j < 27; j++) {
             for(int k = 0; k < 55; k++) {
                 dp[i][j][k] = -1;
             }
         }
    }

    return knightProbabilityHelper(n, k, row, column);
}