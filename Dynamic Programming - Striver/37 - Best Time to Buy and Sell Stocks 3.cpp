// Memoization : 
class Solution {
public:
    int solve(int i, int buy, int transax, vector<int>& prices, vector<vector<vector<int>>> &dp)
    {
        if(i == prices.size() || transax == 2) return 0;
        if(dp[i][buy][transax] != -1) return dp[i][buy][transax];
        if(buy)
        {
            int buy = solve(i+1,0,transax,prices,dp) - prices[i];
            int notBuy = solve(i+1,1,transax,prices,dp);
            dp[i][1][transax] = max(buy,notBuy);
        }
        else
        {
            int sell = solve(i+1,1,transax+1,prices,dp) + prices[i];
            int notSell = solve(i+1,0,transax,prices,dp);
            dp[i][0][transax] = max(sell, notSell);
        }
        return dp[i][buy][transax];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,0,prices,dp);
    }
};
// Tabulation :
int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2,vector<int>(3,0)));
        // base case handled already
        for(int i = prices.size() - 1;i>=0;i--)
        {
           for(int transax = 0;transax<=2;transax++)
            {
                if(transax != 2)
                {
                    dp[i][1][transax] = max(dp[i+1][0][transax] - prices[i], dp[i+1][1][transax]);
                    dp[i][0][transax] = max(dp[i+1][1][transax+1] + prices[i], dp[i+1][0][transax]);
                }
            }
        }
        return dp[0][1][0];
    }
// Space Optimization : 
int maxProfit(vector<int>& prices) {
        vector<vector<int>> prev(2,vector<int>(3,0));
        // base case handled already
        for(int i = prices.size() - 1;i>=0;i--)
        {
            vector<vector<int>> curr(2,vector<int>(3,0));            
            for(int transax = 0;transax<=2;transax++)
            {
                if(transax != 2)
                {
                    curr[1][transax] = max(prev[0][transax] - prices[i], prev[1][transax]);
                    curr[0][transax] = max(prev[1][transax+1] + prices[i], prev[0][transax]);
                }
            }
            prev = curr;
        }
        return prev[1][0];
    }