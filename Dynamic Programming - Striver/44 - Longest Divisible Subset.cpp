class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> lds(nums.size(), 1);
        vector<int> hash(nums.size());
        for(int i = 0;i<nums.size();i++)
        {
            hash[i] = i;
        }
        int idx = 0;
        for(int i = 1;i<nums.size();i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(nums[i] % nums[j] == 0 && lds[j] >= lds[i])
                {
                    lds[i] = 1 + lds[j];
                    hash[i] = j;
                }
            }
            if(lds[idx] < lds[i]) idx = i;
        }
        vector<int> ans(lds[idx]);
        int push = lds[idx] - 1;
        int ss = 0;
        int i = idx;
        while(ss != lds[idx])
        {
            ans[push] = nums[i];
            push--;
            ss++;
            i = hash[i];
        }
        return ans;
    }
};