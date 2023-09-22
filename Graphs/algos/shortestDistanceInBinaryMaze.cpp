//link - https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        vector<vector<int>> minDist(grid.size(),vector<int>(grid[0].size(),1e9));
        minDist[source.first][source.second] = 0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{source.first,source.second}});
        int totRow = grid.size();
        int totCol = grid[0].size();
        while(!q.empty())
        {
            int currDist = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            int dr[] = {-1,1,0,0};
            int dc[] = {0,0,-1,1};
            for(int i=0;i<4;i++)
            {
                int nrow = r + dr[i];
                int ncol = c + dc[i];
                if(nrow>=0 && nrow<totRow && ncol>=0 && ncol<totCol && grid[nrow][ncol] == 1)
                {
                    if(currDist + 1 < minDist[nrow][ncol])
                    {
                        minDist[nrow][ncol] = minDist[r][c] + 1;
                        q.push({minDist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }  
        }
        if(minDist[destination.first][destination.second] == 1e9)
        {
            return -1;
        }
        return minDist[destination.first][destination.second];
    }
};
