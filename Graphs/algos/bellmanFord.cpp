//link - https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-from-the-source-bellman-ford-algorithm
class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> minDist(V,1e8);
        minDist[S] = 0;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<edges.size();j++)
            {
                if(minDist[edges[j][0]] != 1e8 && minDist[edges[j][0]] + edges[j][2] < minDist[edges[j][1]])
                {
                    minDist[edges[j][1]] = minDist[edges[j][0]] + edges[j][2];
                }
            }
        }
        for(int j=0;j<edges.size();j++)
        {
            if(minDist[edges[j][0]] != 1e8 && minDist[edges[j][0]] + edges[j][2] < minDist[edges[j][1]])
            {
                vector<int> v(1,-1);
                return v;
            }
        }
        return minDist;
        
    }
};

