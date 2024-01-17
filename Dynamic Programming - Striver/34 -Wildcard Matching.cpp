class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        if(i == s.size() && j == p.size()) return true;
        if(i == s.size())
        {
            for(int l = j;l<p.size();l++)
            {
                if(p[l] != '*') return false;
            }
            return true;
        }
        if(i != s.size() && j == p.size()) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '?')
        {
            dp[i][j] = solve(i+1,j+1,s,p,dp);
        }
        else if(s[i] != p[j] && p[j] != '*')
        {
            dp[i][j] = 0;
        }
        else
        {
            bool notTake = solve(i,j+1,s,p,dp);
            bool take = solve(i+1,j,s,p,dp);
            // bool takeNnotTake = solve(i+1,j+1,s,p,dp);
            dp[i][j] = take || notTake ;
        }
        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,s,p,dp);
    }
};