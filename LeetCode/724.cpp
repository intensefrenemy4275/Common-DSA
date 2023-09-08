class Solution {
public:
    int pivotIndex(vector<int>& nums) {
          int total_sum = 0;
          for(int i=0;i<nums.size();i++)
          {
              total_sum = total_sum + nums[i];
          }
          int cumSum = 0;
          for(int i=0;i<nums.size();i++)
          {
              int rightSum = total_sum - cumSum - nums[i];
              if(cumSum == rightSum)
              {
                  return i;
              }
              cumSum = cumSum + nums[i];
          }
          return -1;
    }
};
