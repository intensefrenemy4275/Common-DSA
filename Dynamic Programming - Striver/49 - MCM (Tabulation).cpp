#include <bits/stdc++.h>
int matrixChainMultiplication(int* arr, int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    for(int i = n; i>=1 ; i--)
    {
        for(int j = i+1; j<=n ; j++)
        {
            int ans = 1e9;
            for(int k = i;k<=j-1;k++)
            {
                int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                ans = min(ans, steps);
            }      
            dp[i][j] = ans; 
        }
    }
    return dp[1][n];
}