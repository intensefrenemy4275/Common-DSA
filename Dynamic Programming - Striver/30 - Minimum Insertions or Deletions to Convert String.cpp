#include <bits/stdc++.h>
int minimumInsertions(string &str)
{
	        string t  = str;
        reverse(t.begin(), t.end());
        // lps
        int n = t.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // base case handled
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                //match
                if(str[i-1] == t[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                //no match here
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        // cout << dp[n][n] << endl;;
        return t.size() - dp[n][n];
}