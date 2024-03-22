// Memoization :
class Solution {
public:
    int solve(int i, int buy, int transax, vector<int>& prices, vector<vector<vector<int>>> &dp)
    {
        if(transax == 0) return 0;
        if(i == prices.size()) return 0;
        if(dp[i][buy][transax] != -1) return dp[i][buy][transax];
        if(buy)
        {
            int buy = solve(i+1,0,transax,prices,dp) - prices[i];
            int notBuy = solve(i+1,1,transax,prices,dp);
            dp[i][1][transax] = max(buy,notBuy);
        }
        else
        {
            int sell = solve(i+1,1,transax-1,prices,dp) + prices[i];
            int notSell = solve(i+1,0,transax,prices,dp);
            dp[i][0][transax] = max(sell, notSell);
        }
        return dp[i][buy][transax];
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2, vector<int>(k+1,-1)));
        return solve(0,1,k,prices,dp);
    }
};
// Tabulation : 
int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2, vector<int>(k+1,0)));
        for(int i = prices.size()-1;i>=0;i--)
        {
            for(int kk = 0;kk<=k-1;kk++)
            {
                dp[i][1][kk] = max(dp[i+1][0][kk] - prices[i], dp[i+1][1][kk]);
                dp[i][0][kk] = max(dp[i+1][1][kk+1] + prices[i], dp[i+1][0][kk]);
            }
        }
        return dp[0][1][0];
    }
// Space Optimization
int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> prev(2,vector<int>(k+1,0));
        for(int i = prices.size()-1;i>=0;i--)
        {
            vector<vector<int>> curr(2,vector<int>(k+1,0));
            for(int kk = 0;kk<=k-1;kk++)
            {
                curr[1][kk] = max(prev[0][kk] - prices[i], prev[1][kk]);
                curr[0][kk] = max(prev[1][kk+1] + prices[i], prev[0][kk]);
            }
            prev = curr;
        }
        return prev[1][0];
    } 