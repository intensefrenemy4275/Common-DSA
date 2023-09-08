class NumArray {
public:
    vector<int> sums;   
    NumArray(vector<int>& nums) {
      int currSum = 0;
      sums.push_back(currSum);
        for(int i = 0;i<nums.size();i++)
        {
          currSum = currSum + nums[i];
          sums.push_back(currSum);
        }
    }
    
    int sumRange(int left, int right) {
        int answer = sums[right+1] - sums[left];
        return answer;
    }
};
