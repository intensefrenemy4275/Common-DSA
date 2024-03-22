#include <bits/stdc++.h>
vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	vector<int> hash(n);
	for(int i = 0;i<n;i++) hash[i] = i;
	vector<int> lis(n,1);
	int idx = 0;
	for(int i = 1;i<n;i++)
	{
		for(int j = 0;j<i;j++)
		{
			if(arr[j] < arr[i] && lis[j] >= lis[i])
			{
				lis[i] = 1 + lis[j];
				hash[i] = j;
			}
		}
		if(lis[idx] < lis[i]) idx = i;
	}
	vector<int> ans(lis[idx]);
	int s = 0;
	int push = lis[idx] - 1;
	while(s != ans.size())
	{
		ans[push] = arr[idx];
		idx = hash[idx];
		s++;
		push--;
	}
	return ans;
}