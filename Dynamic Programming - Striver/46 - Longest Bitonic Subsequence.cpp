#include <bits/stdc++.h>
int solve(int i, int prev, int up, vector<int>& arr, vector<vector<vector<int>>> &dp)
{
	if(i == arr.size() + 1) return 0;
	if(dp[i][prev][up] != -1) return dp[i][prev][up];
	if(up == 1)
	{
		int notTake = solve(i+1,prev,1,arr,dp);
		int changeOver = solve(i,prev,0,arr,dp);
		int take = 0;
		if(prev == 0 || arr[i-1] > arr[prev-1])
		{
			take = 1 + solve(i+1,i,1,arr,dp);
		}
		dp[i][prev][1] = max(notTake, max(changeOver, take));
	} 
	else
	{
		int notTake = solve(i+1,prev,0,arr,dp);
		int take = 0;
		if(prev == 0|| arr[i-1] < arr[prev - 1])
		{
			take = 1 + solve(i+1,i,0,arr,dp);
		}
		dp[i][prev][0] = max(take, notTake);
	}
	return dp[i][prev][up];
}
int longestBitonicSubsequence(vector<int>& arr, int n)
{
	vector<vector<vector<int>>> dp(arr.size()+2,vector<vector<int>>(arr.size()+2,vector<int>(2,0)));
	for(int i = arr.size(); i>=1; i--)
	{
		for(int j = 0; j<=arr.size(); j++)
		{
			if(j == 0 || arr[i-1] < arr[j-1])
				dp[i][j][0] = max(1 + dp[i+1][i][0], dp[i+1][j][0]);
			else
				dp[i][j][0] = dp[i+1][j][0];
			if(j == 0 || arr[i-1] > arr[j-1])
				dp[i][j][1] = max(dp[i+1][j][1], max(dp[i+1][i][1], dp[i][j][0]));
			else
				dp[i][j][1] = max(dp[i+1][j][1], dp[i][j][0]);
		}
	}
	return dp[1][0][1];
}