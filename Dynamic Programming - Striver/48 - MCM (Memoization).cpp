#include <bits/stdc++.h>
int solve(int i, int j, int* arr, int n, vector<vector<int>> &dp)
{
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 1e9;
    for(int k = i;k<=j-1;k++)
    {
        int steps = arr[i-1] * arr[k] * arr[j] + solve(i,k,arr,n,dp) + solve(k+1,j,arr,n,dp);
        ans = min(ans, steps);
    }
    dp[i][j] = ans;
    return ans;
}
int matrixChainMultiplication(int* arr, int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
    return solve(1,n,arr,n,dp);
}