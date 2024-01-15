#include <bits/stdc++.h> 
bool solve(int idx, int target, vector<vector<int>> &canItBe, vector<int> &arr)
{
    if(target == 0) return true;
    if(idx == arr.size() - 1) return arr[idx] == target;
    if(canItBe[idx][target] != -1) return canItBe[idx][target];
    bool take,notTake;
    notTake = solve(idx + 1,target,canItBe,arr);
    take = false;
    if(arr[idx] <= target)
    {
        take = solve(idx +1, target - arr[idx],canItBe,arr);
    }
    if(take || notTake) canItBe[idx][target] = 1;
    else canItBe[idx][target] = 0;
    return canItBe[idx][target];
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> canItBe(n+1,vector<int>(k+1,-1));
    return solve(0,k,canItBe,arr);
}