class Solution {
public:
    bool solve(int idx, int target, vector<vector<int>> &canItBe, vector<int>& nums)
    {
        if(idx == nums.size()-1)
        {
            return nums[idx] == target;
        }
        if(canItBe[idx][target] != -1)
            return canItBe[idx][target];
        bool take,notTake;
        take = false;
        notTake = solve(idx + 1, target,canItBe, nums);
        if(target >= nums[idx])
        {
            take = solve(idx + 1,target - nums[idx],canItBe,nums);
        }
        if(take || notTake)
            canItBe[idx][target] = true;
        else
            canItBe[idx][target] = false;
        return canItBe[idx][target];

    }
    bool canPartition(vector<int>& nums) {
        int totS = 0;
        for(auto i : nums)
            totS+=i;
        if(totS % 2 == 1) return false;
        else 
        {
            vector<vector<int>> canItBe(nums.size() - 1 ,vector<int>(totS/2 + 1,-1));
            return solve(0,totS/2,canItBe,nums);   
        }
    }
};