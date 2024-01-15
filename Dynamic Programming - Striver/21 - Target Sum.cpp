class Solution {
public:
    int solve(int idx,int currVal, int target, map<pair<int,int>,int> &map, vector<int>& nums)
    {
        if(idx == nums.size() - 1)
        {
            int ans = 0;
            if(currVal + nums[idx] == target) ans++;
            if(currVal - nums[idx] == target) ans++;
            return ans;
        }
        if(map.find({idx,currVal}) != map.end())
        {
            return map[{idx,currVal}];
        }
        int plus = solve(idx+1,currVal+nums[idx],target,map,nums);
        int minus = solve(idx+1,currVal-nums[idx],target,map,nums);
        map[{idx,currVal}] = plus + minus;
        return map[{idx,currVal}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>,int> map;
        return solve(0,0,target,map,nums);
    }
};