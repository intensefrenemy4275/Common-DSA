#define MOD 1e9+7
#include <math.h>
int solve(int idx, int target, vector<int>& nums, vector<vector<int>> &ways)
    {
        if(target == 0) return 1;
        if(idx == nums.size()-1)
        {
            if(nums[idx] == target) return 1;
            else return 0;
        }
        if(ways[idx][target] != -1) return ways[idx][target];
        int notTake = (solve(idx + 1, target,nums,ways)) % (1000000007);
        int take = 0;
        if(target >= nums[idx])
        {
            take = (solve(idx+1,target - nums[idx],nums,ways)) % (1000000007);
        }
        ways[idx][target] = (take + notTake)%(1000000007);
        return ways[idx][target];
    }
int findWays(vector<int>& nums, int target)
{
    sort(nums.begin(),nums.end());
    if(target == 0)
    {
        int cnt = 0;
        for(auto i : nums)
        {
            if(i == 0) cnt++;
        }
        return pow(2,cnt);
    }
	vector<vector<int>> ways(nums.size(), vector<int>(target +1,-1));
    return solve(0,target,nums,ways);
}