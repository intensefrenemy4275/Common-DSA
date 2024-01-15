#include <bits/stdc++.h> 
int solve(int idx, int currWt, int maxWeight,vector<int> &weight, vector<int> &value, vector<vector<int>> &maxVal)
{
	if(idx == weight.size() - 1)
	{
		if(currWt + weight[idx] <= maxWeight)
			return value[idx];
			return 0;
	}
	if(maxVal[idx][currWt] != -1) return maxVal[idx][currWt];
	int notTake = solve(idx + 1, currWt, maxWeight, weight, value, maxVal);
	int take = 0;
	if(currWt + weight[idx] <= maxWeight)
	{
		take = value[idx] + solve(idx + 1,currWt + weight[idx],maxWeight,weight,value,maxVal);
	}
	maxVal[idx][currWt] = max(take,notTake);
	return maxVal[idx][currWt];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> maxVal(n,vector<int>(maxWeight+1,-1));
	return solve(0,0,maxWeight,weight,value,maxVal);
}