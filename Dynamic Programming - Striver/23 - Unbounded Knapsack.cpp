#include<bits/stdc++.h>
int solve(int idx, int wt, vector<int> &profit,vector<int> &weight, vector<vector<int>> &maxVal)
{
    if(wt == 0) return 0;
    if(idx == weight.size() - 1)
    {
        if(wt >= weight[idx])
        {
            // take
            return wt/weight[idx] * profit[idx];
        }
        //not take
        else return 0;
    }
    if(maxVal[idx][wt] != -1) return maxVal[idx][wt];
    int notTake = solve(idx + 1, wt, profit,weight,maxVal);
    int take = 0;
    if(wt >= weight[idx])
    {
        take = profit[idx] + solve(idx,wt - weight[idx],profit,weight,maxVal);
    } 
    maxVal[idx][wt] = max(take,notTake);
    return maxVal[idx][wt];
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> maxVal(n, vector<int>(w+1,-1));
    return solve(0,w,profit,weight,maxVal);
}