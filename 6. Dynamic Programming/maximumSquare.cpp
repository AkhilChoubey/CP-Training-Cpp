// Given an m x n binary matrix filled with 0's and 1's,
// find the largest square containing only 1's and return its area.


int maximumSquares(vector<vector<char>> &matrix) {

    int dp[300][300];
    int ans = 0;
    
    //initializing 1st column
    for(int i = 0; i < matrix.size(); i++) {
        if(matrix[i][0] == '1') {
            ans = 1;
            dp[i][0] = 1;
        }
        else {
            dp[i][0] = 0;
        }
    }

    //initializing 1st row
    for(int j = 0; j < matrix[0].size(); j++) {
        if(matrix[0][j] == '1') {
            ans = 1;
            dp[0][j] = 1;
        }
        else {
            dp[0][j] = 0;
        }
    }

    for(int i = 1; i < matrix.size(); i++) {
        for(int j = 1; j < matrix[0].size(); j++) {
            if(matrix[i])[j] == '1') {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                ans = max(ans, dp[i][j]);
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    // we have to return area and ans is side of largest square . so, ans*ans;
    return ans*ans;
}
