class Solution {
public:
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>> &dp)
    {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k = i; k<=j ; k++)
        {
            int cost = cuts[j+1] - cuts[i-1] + solve(i,k-1,cuts,dp) + solve(k+1,j,cuts,dp);
            mini = min(cost, mini);
        }
        dp[i][j] = mini;
        return dp[i][j];
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(),-1));
        return solve(1,cuts.size()-2,cuts,dp);
    }
};