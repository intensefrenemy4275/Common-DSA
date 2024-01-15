#include<bits/stdc++.h>
int solve(int toBeCut ,int length, vector<int> &price, vector<vector<int>> &maxProfit)
{
	if(toBeCut == price.size() + 1)
		return 0;
	if(maxProfit[toBeCut][length] != -1) return maxProfit[toBeCut][length];
	int notCut = solve(toBeCut+1,length,price,maxProfit);
	int cut = 0;
	if(toBeCut <= length)
	{
		cut = price[toBeCut - 1] + solve(toBeCut,length - toBeCut,price,maxProfit);
	}
	maxProfit[toBeCut][length] = max(cut,notCut);
	return maxProfit[toBeCut][length];
}
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> maxProfit(n+1,vector<int>(n+1,-1));
	return solve(1,n,price,maxProfit);
}