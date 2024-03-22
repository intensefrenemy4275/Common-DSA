// Tabulation :
int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2,0));
        for(int i = prices.size() - 1;i >= 0; i--)
        {
            dp[i][1] = max(dp[i+1][0] - prices[i], dp[i+1][1]);
            dp[i][0] = max(dp[i+1][1] + prices[i] - fee, dp[i+1][0]);
        }
        return dp[0][1];
    }
// Space Optimization : 
int maxProfit(vector<int>& prices, int fee) {
        // vector<vector<int>> dp(prices.size() + 1, vector<int>(2,0));
        int prev[] = {0,0};
        int curr[] = {0,0};
        for(int i = prices.size() - 1;i >= 0; i--)
        {
            curr[1] = max(prev[0] - prices[i], prev[1]);
            curr[0] = max(prev[1] + prices[i] - fee, prev[0]);
            prev[1] = curr[1];
            prev[0] = curr[0];
        }
        return prev[1];
    }