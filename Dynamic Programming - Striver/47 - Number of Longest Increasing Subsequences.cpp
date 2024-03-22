class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> count(nums.size(),1);
        vector<int> lis(nums.size(),1);
        int ll = INT_MIN;
        int ans = 0;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            for(int j = 0; j<i ; j++)
            {
                if(nums[i] > nums[j])
                {
                    if(lis[j] >= lis[i])
                    {
                        lis[i] = 1 + lis[j];
                        count[i] = count[j];
                    }
                    else if(lis[j] == lis[i] - 1)
                        count[i] = count[i] + count[j];
                }
            }
            if(lis[i] > ll)
            {
                ll = lis[i];
                ans = count[i];
            }
            else if(lis[i] == ll)
            {
                ans += count[i];
            }
        }
        return ans;
    }
};