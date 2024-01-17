//Greedy : (Fastest)
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
       int ans = 0;
       for(int i=1;i<prices.size();i++)
       {
           if(prices[i]>prices[i-1])
           {
               ans = ans + prices[i] - prices[i-1];
           }
       }
       return ans;
    }
};
// Memoization
int solve(int i, int buy, vector<int>& prices, vector<vector<int>> &maxProfit)
    {
        if(i == prices.size()) return 0;
        if(maxProfit[i][buy] != -1) return maxProfit[i][buy];
        if(buy == 1) // buying is a possible
        {
            int buy = solve(i+1,0,prices,maxProfit) - prices[i];
            int notBuy = solve(i+1,1,prices,maxProfit);
            maxProfit[i][1] = max(buy,notBuy);
        }
        else // selling is possible
        {
            int sell = solve(i+1,1,prices,maxProfit) + prices[i];
            int notSell = solve(i+1,0,prices,maxProfit);
            maxProfit[i][0] = max(sell,notSell);
        }
        return maxProfit[i][buy];
    }
    int maxProfit(vector<int>& prices) 
    {
       vector<vector<int>> maxProfit(prices.size(), vector<int>(2,-1));
       return solve(0,1,prices,maxProfit);
    }
// Tabulation : 
int maxProfit(vector<int>& prices) 
    {
       vector<vector<int>> maxProfit(prices.size() + 1, vector<int>(2,-1));
       // base case
       maxProfit[prices.size()][0] = 0;
       maxProfit[prices.size()][1] = 0;
       // recurrence
       for(int i = prices.size() - 1; i>=0;i--)
       {
           maxProfit[i][0] = max(maxProfit[i+1][1] + prices[i], maxProfit[i+1][0]);
           maxProfit[i][1] = max(maxProfit[i+1][0] - prices[i], maxProfit[i+1][1]); 
           // copied the recurrence
       }
       return maxProfit[0][1];
    }
// Space Optimized :
int maxProfit(vector<int>& prices) 
    {
        vector<int> prev(2,0);
       // base case
       prev[0] = prev[1] = 0;
       // recurrence
       for(int i = prices.size() - 1; i>=0;i--)
       {
           vector<int> curr(2,0);
           curr[0] = max(prev[1] + prices[i], prev[0]);
           curr[1] = max(prev[0] - prices[i], prev[1]);
           // copied the recurrence
           prev = curr;
       }
       return prev[1];
    }
// Space Optimization x 100000000
int maxProfit(vector<int>& prices) 
    {
        int a,b;
       // base case
       a = b = 0;
       // recurrence
       for(int i = prices.size() - 1; i>=0;i--)
       {
           int a1, b1;
           a1 = max(b + prices[i], a);
           b1 = max(a - prices[i], b);
           // copied the recurrence
           a = a1;
           b = b1;
       }
       return b;
    }