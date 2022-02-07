
int dp[55][55][55];
int xMoves[4] = {0, 0, 1, -1};
int yMoves[4] = {1, -1, 0, 0};

int outOfBoundaryHelper(int m, int n, int maxMove, int i, int j) {

    if(i < 0 || j < 0 || i >= m || j >= n) {
        return 1;
    }

    if(maxMove == 0) {
        return 0;
    }

    if(dp[i][j][maxMove] != -1) {
        return dp[i][j][maxMove];
    }

    int ans = 0;
    for(int k = 0; k < 4; k++) {
        int x = i + xMoves[k];
        int y = j + yMoves[k];
        ans = ans + outOfBoundaryHelper(m, n, maxMove - 1, x, y);
    }

    dp[i][j][maxMove] = ans;
    return ans;
}


int outOfBoundary(int m, int n, int maxMove, int startRow, int startColumn) {
    
    for(int i = 0; i < 55; i++) {
        for(int j = 0; j < 55; j++) {
            for(int k = 0; k < 55; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    return outOfBoundaryHelper(m, n, maxMove, startRow, startColumn) % 100000007;
}







/// only recursive approach

int xMoves[4] = {0, 0, 1, -1};
int yMoves[4] = {1, -1, 0, 0};

int outOfBoundaryHelper(int m, int n, int maxMove, int i, int j) {

    if(i < 0 || j < 0 || i >= m || j >= n) {
        return 1;
    }

    if(maxMoves == 0) {
        return 0;
    }

    int ans = 0;
    for(int k = 0; k < 4; k++) {
        int x = i + xMoves[k];
        int y = j + yMoves[k];
        ans = ans + outOfBoundaryHelper(m, n, maxMove - 1, x, y);
    }

    return ans;
}


int outOfBoundary(int m, int n, int maxMove, int startRow, int startColumn) {
    
    for(int i = 0; i < 55; i++) {
        for(int j = 0; j < 55; j++) {
            for(int k = 0; k < 55; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    return outOfBoundaryHelper(m, n, maxMove, startRow, startColumn) % 100000007;
}