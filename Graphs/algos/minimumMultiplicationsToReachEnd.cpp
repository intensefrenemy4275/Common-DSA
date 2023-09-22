//link - https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-multiplications-to-reach-end
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start == end)
            return 0;
            
        int mod = 100000;
        vector<int> minSteps(mod,1e9);
        minSteps[start] = 0;
        queue<pair<int,int>> q;
        q.push({0,start});
        while(!q.empty())
        {
            int currSteps = q.front().first;
            int node = q.front().second;
            q.pop();
            for(int i=0;i<arr.size();i++)
            {
                int newNode = (arr[i] * node)%mod;
                int newSteps = currSteps + 1;
                if(newSteps < minSteps[newNode])
                {
                    minSteps[newNode] = newSteps;
                    q.push({newSteps,newNode});
                    if(newNode == end) return newSteps;
                }
            }
        }
        return -1;
    }
};
