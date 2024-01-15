#include <bits/stdc++.h> 
int solve(int index, vector<int> &nums, unordered_map<int,int> &map)
{
    if(index >= nums.size())
        return 0;
    if(map.find(index) != map.end())
    {
        return map[index];
    }
    // pick
    int pick = nums[index] + solve(index + 2,nums,map);
    // dont pick
    int notPick = solve(index+1,nums,map);
    map[index] = max(pick,notPick);
    return map[index];
}
int maximumNonAdjacentSum(vector<int> &nums){
    unordered_map<int,int> map;
    return solve(0,nums,map);
}