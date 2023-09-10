//link - https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1
class Solution 
{
    public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int freshCount = 0;
        int rotCount = 0;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++)
        {
          for(int j=0;j<grid[0].size();j++)
          {
            if(grid[i][j] == 2)
            {
              vis[i][j] = 1;
              q.push(make_pair(i,j));
            }
            if(grid[i][j] == 1)
              freshCount++;
          }
        }
        int ans = 0;
        while(!q.empty())
        {
          int n = q.size();
          bool yes = false;
          for(int i=0;i<n;i++)
          {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int dx[] = {0,0,1,-1};
            int dy[] = {1,-1,0,0};
            for(int i=0;i<4;i++)
            {
              int nx = x + dx[i];
              int ny = y + dy[i];
              int totX = grid.size();
              int totY = grid[0].size();
              if(nx >= 0 && nx<totX && ny >=0 && ny <totY && vis[nx][ny] != 1 && grid[nx][ny] == 1)
              {
                rotCount++;
                yes = true;
                q.push(make_pair(nx,ny));
                vis[nx][ny] = 1;
                grid[nx][ny] = 2;
              }
            }
          }
          if(yes)
            ans++;
        }
        if(freshCount == rotCount)
          return ans;
        return -1;
    }
};
