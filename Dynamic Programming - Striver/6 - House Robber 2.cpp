class Solution {
public:
int solve(int index, unordered_map<int,int> &map1, unordered_map<int,int> &map2, vector<int>& nums, bool first)
{
    if(index >= nums.size())
    {
        return 0;
    }
    if(index == 0)
    {
        //pick
        int pick = nums[0] + solve(index + 2,map1,map2,nums,true);
        //not pick
        int notPick = solve(index+1,map1,map2,nums,false);
        return max(pick,notPick);
    }
    if(index == nums.size() - 1)
    {
        if(first)
        {
            return 0;
        }
        else
        {
            return nums[index];
        }
    }
    if(first && map1.find(index) != map1.end())
    {
        return map1[index];
    }
    if(!first && map2.find(index) != map2.end())
    {
        return map2[index];
    }
    int pick = nums[index] + solve(index+2,map1,map2,nums,first);
    int npick = solve(index +1,map1,map2,nums,first);
    int temp = max(pick,npick);
    if(first)
    {
        map1[index] = temp;
    }
    else
    {
        map2[index] = temp;
    }
    return temp;  
}
    int rob(vector<int>& nums) {
        unordered_map<int,int> map1;
        unordered_map<int,int> map2;
        return solve(0,map1,map2,nums,false);
    }
};