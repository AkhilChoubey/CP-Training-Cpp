
// Bottom-Up Approach

int uniquePaths(vector<vector<int>> &grid)
{
    int dp[105][105];

    int n = grid.size();
    int m = grid[0].size();

    // initializing all dp array element with 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = 0;
        }
    }

    // initializing column
    for (int i = 0; i < n; i++)
    {

        // if grid value is 1 that means there is obstacle and we cannot go throught that path
        if (grid[i][0] == 1)
        {
            break;
        }
        dp[i][0] = 1;
    }

    // initializing row
    for (int j = 0; j < m; j++)
    {
        // if grid value is 1 that means there is obstacle and we cannot go throught that path
        if (grid[0][j] == 1)
        {
            break;
        }
        dp[0][j] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[n - 1][m - 1];
}