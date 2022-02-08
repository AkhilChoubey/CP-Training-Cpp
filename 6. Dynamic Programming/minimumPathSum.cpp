
int minimuPathSum(vector<vector<int>> &nums) {
    int dp[100][100];
    dp[0][0] = nums[0][0];

    //initializing 1st column of dp by it's own value + value of previous index.
    for(int i = 1; i < nums.size(); i++) {
        dp[i][0] = dp[i-1][0] + nums[i][0];
    }

    //initializing 1st row of dp by it's own value + value of previous index.
    for(int j = 1; j < nums[0].size(); i++) {
        dp[0][j] = dp[0][j-1] + dp[0][j];
    }

    
    for(int i = 1; i < nums.size(); i++) {
        for(int j = 1; j < nums[0].size(); j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + nums[i][j];
        }
    }

    return dp[nums.size() - 1][nums[0].size() - 1];
}