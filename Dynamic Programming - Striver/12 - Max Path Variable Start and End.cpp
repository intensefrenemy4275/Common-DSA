#include <bits/stdc++.h> 
bool valid(int r, int c,int m, int n)
{
    if(r < m && c < n && r >= 0 && c >= 0) return true;
    return false;
}
int solve(int r, int c, vector<vector<int>> &matrix, vector<vector<int>> &maxCost)
{
    int m = matrix.size();
    int n = matrix[0].size();
    if(r == m-1)
        return matrix[r][c];
    if(maxCost[r][c] != INT_MIN)
        return maxCost[r][c];
    int val = INT_MIN;
    for(int i=-1;i<=1;i++)
    {
        int nr = r+1;
        int nc = c + i;
        if(valid(nr,nc,m,n))
        {
            val = max(val,matrix[r][c] + solve(nr,nc,matrix,maxCost));
        }
    }
    maxCost[r][c] = val;
    return val;
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    vector<vector<int>> maxCost(matrix.size(), vector<int>(matrix[0].size(),INT_MIN));
    int totC = matrix[0].size();
    int ans = INT_MIN;
    for(int i=0;i<totC;i++)
    {
        ans = max(ans,solve(0,i,matrix,maxCost));
    } 
    return ans;
}