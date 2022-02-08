
int dp[200][200];

int rec(vector<vector<int>> &triangle, int i, int j) {

    if(i == triangle.size() || j == triangle.size()) {
        return 0;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans = min(rec(triangle, i+1, j), rec(triangle, i+1, j+1)) + triangle[i][j];

    dp[i][j] = ans;
    return ans;
}



int minimumSumTriangle(vector<vector<int>> &triangle) {

    for(int  i = 0; i < 200; i++) {
        for(int j = 0; j < 200; j++) {
            dp[i][j] = -1;
        }
    }

    return rec(triangle, 0, 0);
}