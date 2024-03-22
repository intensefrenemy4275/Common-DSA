// Memoization :
int solve(int i, int buy, int coolDown, vector<int>& prices, vector<vector<vector<int>>> &dp)
    {
        if(i == prices.size()) return 0;
        if(dp[i][buy][coolDown] != -1) return dp[i][buy][coolDown];
        if(buy)
        {
            int notBuy = solve(i+1,1,0,prices,dp);
            int buy = 0;
            if(coolDown == 0)
            {
                buy = solve(i+1,0,0,prices,dp) - prices[i];
            }
            dp[i][1][coolDown] = max(buy,notBuy);
        }
        else
        {
            int sell = solve(i+1,1,1,prices,dp) + prices[i];
            int notSell = solve(i+1,0,0,prices,dp);
            dp[i][0][coolDown] = max(sell,notSell);
        }
        return dp[i][buy][coolDown];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2, vector<int>(2,-1)));
        return solve(0,1,0,prices,dp);
    }
// Tabulation : 
int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2, vector<int>(2,0)));
        // base case handled
        for(int i = prices.size()-1;i>=0;i--)
        {
            dp[i][0][0] = max(dp[i+1][1][1] + prices[i], dp[i+1][0][0]);
            dp[i][1][0] = max(dp[i+1][0][0] - prices[i], dp[i+1][1][0]);
            dp[i][1][1] = dp[i+1][1][0];
        }
        return dp[0][1][0];
    }
// Space Optimized :
 int maxProfit(vector<int>& prices) {
        // vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2, vector<int>(2,0)));
        // base case handled
        vector<vector<int>> prev(2,vector<int>(2,0));
        vector<vector<int>> curr(2,vector<int>(2,0));
        for(int i = prices.size()-1;i>=0;i--)
        {
            // vector<vector<int>> curr(2,vector<int>(2,0));
            curr[0][0] = max(prev[1][1] + prices[i], prev[0][0]);
            curr[1][0] = max(prev[0][0] - prices[i], prev[1][0]);
            curr[1][1] = prev[1][0];
            prev = curr;
        }
        return prev[1][0];
    }