//link - https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=path-with-minimum-effort
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int srcR = 0;
        int srcC = 0;
        int totR = heights.size();
        int totC = heights[0].size();
        vector<vector<int>> minEffort(heights.size(),vector<int>(heights[0].size(),1e9));
        minEffort[srcR][srcC] = 0;
        set<pair<int,pair<int,int>>> set;
        set.insert({0,{0,0}});
        while(!set.empty())
        {
            auto it = *(set.begin());
            int currEffort = it.first;
            int r = it.second.first;
            int c = it.second.second;
            set.erase(it);
            int dr[] = {-1,1,0,0};
            int dc[] = {0,0,-1,1};
            for(int i=0;i<4;i++)
            {
                int nrow = r + dr[i];
                int ncol = c + dc[i];
                // int temp = currEffort;
                if(nrow<totR && nrow>=0 && ncol<totC && ncol>=0)
                {
                    int newEff = abs(heights[nrow][ncol] - heights[r][c]);
                    int temp = max(currEffort,newEff);
                    if(temp < minEffort[nrow][ncol])
                    {
                        if(minEffort[nrow][ncol] != 1e9)
                        {
                            set.erase({minEffort[nrow][ncol],{nrow,ncol}});
                        }
                        minEffort[nrow][ncol] = temp;
                        set.insert({minEffort[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return minEffort[totR-1][totC-1];
    }
};
