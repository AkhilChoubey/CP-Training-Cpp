
// Buttom up approach

int uniquePaths(int n, int m)
{
    int dp[47][47]; // size will be some what greater than contraint size

    // initializing 1st column with 1
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    // initializing 1st row with 1
    for (int j = 0; j < m; j++) {
        dp[0][j] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[n - 1][m - 1];
}