#include<bits/stdc++.h>
int lcs(string &str1, string &str2){
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // base case handled
    int ans = -1;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(str1[i-1] == str2[j-1]) // match
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else // no match
            {
                dp[i][j] = 0;
            }
            ans = max(ans,dp[i][j]);
        }
    }
    return ans;

}