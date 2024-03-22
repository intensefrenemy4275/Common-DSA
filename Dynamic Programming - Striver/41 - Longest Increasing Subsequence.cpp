// Memoization :
int solve(int i, int prev, vector<int>& nums, vector<vector<int>> &dp)
    {
        if(i == nums.size() + 1) // 1 based indexing
        {
            return 0;
        }
        if(dp[i][prev] != -1) return dp[i][prev];
        int notTake = solve(i+1,prev,nums,dp);
        int take = 0;
        if(prev == 0 || nums[i-1] > nums[prev - 1])
        {
            take = 1 + solve(i+1,i,nums,dp);
        }
        dp[i][prev] = max(take, notTake);
        return dp[i][prev];
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(1,0,nums,dp);
    }
// Tabulation :
int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+2,vector<int>(nums.size()+1,0));
        // base case handled, dp[nums.size()+1][any idx] = 0;
        for(int i = nums.size(); i>=1;i--)
        {
            for(int prev = 0; prev <= nums.size(); prev++)
            {
                if(prev == 0 || nums[i-1] > nums[prev - 1])
                {
                    dp[i][prev] = max(1 + dp[i+1][i], dp[i+1][prev]);
                }
                else
                {
                    dp[i][prev] = dp[i+1][prev];
                }
            }
        }
        return dp[1][0];
    }
// Space Optimized :
int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>> dp(nums.size()+2,vector<int>(nums.size()+1,0));
        // base case handled, dp[nums.size()+1][any idx] = 0;
        vector<int> next(nums.size()+1,0);
        vector<int> curr(nums.size()+1,0);
        for(int i = nums.size(); i>=1;i--)
        {
            for(int prev = 0; prev <= nums.size(); prev++)
            {
                if(prev == 0 || nums[i-1] > nums[prev - 1])
                {
                    curr[prev] = max(1 + next[i], next[prev]);
                }
                else
                {
                    curr[prev] = next[prev];
                }
            }
            next = curr;
        }
        return next[0];
    }