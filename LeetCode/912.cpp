class Solution {
public:
    int partition(vector<int> &nums, int l, int h)
    {
      int pivot = nums[l];
      int i=l+1;
      int cnt = 0;
      while(i<=h)
      {
          if(nums[i] < pivot)
          {
              cnt++;
          }
          i++;
      }
      int new_idx = cnt + l;
      swap(nums[l],nums[new_idx]);
      i=l;
      int j=h;
      while(i < new_idx && j > new_idx)
      {
          while(nums[i] <= pivot)
          {
              i++;
          }
          while(nums[j] > pivot)
          {
              j--;
          }
          if(i<j)
          {
              swap(nums[i],nums[j]);
          }
      }
    return new_idx;
    }
    void quickSort(vector<int> &nums, int l, int h)
    {
        if(l>=h)
        {
            return;
        }
        int pivot = partition(nums,l, h);
        quickSort(nums , l, pivot - 1);
        quickSort(nums , pivot + 1, h);
    }
    vector<int> sortArray(vector<int>& nums) {
            quickSort(nums , 0, nums.size() -1);
            return nums;
    }
};
