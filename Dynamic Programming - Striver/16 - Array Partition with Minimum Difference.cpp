bool solve(int idx , vector<int>& nums, vector<vector<int>> &canItBe, int target)
{
    if(target == 0) return true;
    if(idx == nums.size()-1) return nums[idx] == target;
    if(canItBe[idx][target] != -1) return canItBe[idx][target];
    bool notTake = solve(idx+1,nums,canItBe,target);
    bool take = false;
    if(target >= nums[idx])
        take = solve(idx + 1,nums,canItBe,target - nums[idx]);
    canItBe[idx][target] = take || notTake;
    return canItBe[idx][target];
}
int minSubsetSumDifference(vector<int>& nums, int n)
{
	int totSum = 0;
    for(auto i: nums) totSum += i;
    vector<vector<int>> canItBe(nums.size(),vector<int>(totSum+1,-1));
    int ans = INT_MAX;
    for(int i = 0; i<= totSum/2 + 1; i++)
    {
        if(solve(0,nums,canItBe,i))
        {
            ans = min(ans, abs(totSum - 2 * i));
        }
    }
    return ans;
}