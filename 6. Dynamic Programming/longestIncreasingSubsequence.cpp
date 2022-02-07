

int lengthOfLIS(vector<int>& nums) {
    int N = nums.size();
    int maxLen = 1;
    vector<int> dp(N + 1, 1);

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] < nums[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
                maxLen = max(maxLen, dp[i]);
            }
        } 
    }
    return maxLen;
}