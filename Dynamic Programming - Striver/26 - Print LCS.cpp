#include <bits/stdc++.h>
string findLCS(int n, int m,string &s1, string &s2){
	n = s1.length(); m = s2.length();
	vector<vector<int>>	dp(n+1,vector<int>(m+1,0));
	// base case handled by initialising everything to 0
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			if(s1[i-1] == s2[j-1]) // match
			{
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else // no match
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	string ans = "";
	int i = n;
	int j = m;
	while(i >= 1 && j >= 1)
	{
		if(s1[i-1] == s2[j-1]) // match
		{
			ans = s1[i-1] + ans;
			i--;j--;
		}
		else // no match
		{
			if(dp[i-1][j] > dp[i][j-1])
			{
				i--;
			}
			else j--;
		}
	}
	return ans;
}