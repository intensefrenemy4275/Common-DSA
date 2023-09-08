class NumArray {
public:
  vector<int> sums;
  NumArray(vector<int>& nums) {
        int currSum = 0;
        for(int i=0;i<=nums.size();i++)
        {
            sums.push_back(currSum);
            currSum = currSum + nums[i];
        }
        
    }
    
    void update(int index, int val) {
        int diff = val -  (sums[index + 1] - sums[index]);
          for(int i=index+1;i<sums.size();i++)
          {
              sums[i] = sums[i] + diff;
          }
    }
    
    int sumRange(int left, int right) {
        int ans = sums[right + 1] - sums[left];
        return ans;
    }
};
