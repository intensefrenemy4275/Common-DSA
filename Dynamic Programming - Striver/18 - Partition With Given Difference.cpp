#define MOD 1000000007
#include <bits/stdc++.h> 
int solve(int idx, int target, vector<int> &arr, vector<vector<int>> &ways)
{
    if(idx == arr.size() - 1)
    {
        if(arr[idx] == 0 && target == 0) return 2;
        if(arr[idx] == target) return 1;
        if(target == 0) return 1;
        return 0;
    }
    if(ways[idx][target] != -1) return ways[idx][target];
    int notTake = (solve(idx + 1, target, arr,ways)) % MOD;
    int take = 0;
    if(target >= arr[idx]) take = (solve(idx+1,target-arr[idx],arr,ways)) % MOD;
    ways[idx][target] = (take + notTake) % MOD;
    return ways[idx][target];
}
int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(auto i : arr) sum+=i;
    int s1 = (sum + d) / 2;
    vector<vector<int>> ways(arr.size(),vector<int>(s1 + 1,-1));
    if((sum + d) % 2 == 1) return 0;
    else return solve(0,s1,arr,ways);
}