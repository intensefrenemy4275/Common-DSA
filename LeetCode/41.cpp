class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      unordered_set<int> set;
      for(int i=0;i<nums.size();i++)
      {
          if(nums[i]<=0)
          {
            continue;
          }
          set.insert(nums[i]);
      }
      int ans = 1;
      while(set.contains(ans))
      {
        ans++;
      }
      return ans;
    }
};
