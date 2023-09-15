//link - https://practice.geeksforgeeks.org/problems/number-of-enclaves/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-enclaves
class Solution {
  public:
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int r, int c)
    {
      vis[r][c] = 1;
      int dr[] = {0,0,-1,1};
      int dc[] = {1,-1,0,0};
      int totR= grid.size();
      int totC = grid[0].size();
      for(int i=0;i<4;i++)
      {
        int nrow = r + dr[i];
        int ncol = c + dc[i];
        if(nrow>=0 && nrow<totR && ncol>=0 && ncol<totC && vis[nrow][ncol] != 1 && grid[nrow][ncol] == 1)
        {
          dfs(grid,vis,nrow,ncol);
        }
      }
      return;
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        int oneCount = 0;
        for(int i=0;i<grid.size();i++)
        {
          for(int j=0;j<grid[0].size();j++)
          {
            if(grid[i][j] == 1)
            {
              oneCount++;
            }
          }
        }
      int rowTrav[] = {0,grid.size()-1};
      int colTrav[] = {0,grid[0].size()-1};
      for(int i=0;i<=1;i++)
      {
        int row = rowTrav[i];
        for(int j=0;j<grid[0].size();j++)
        {
          if(vis[row][j] != 1 && grid[row][j] == 1)
          {
            dfs(grid,vis,row,j);
          }
        }
      }

      for(int i = 0;i<=1;i++)
      {
        int col = colTrav[i];
        for(int j =0;j<grid.size();j++)
        {
          if(vis[j][col] != 1 && grid[j][col] == 1)
          {
            dfs(grid,vis,j,col);
          }
        }
      }
      int count = 0;
      for(int i=0;i<grid.size();i++)
      {
        for(int j=0;j<grid[0].size();j++)
        {
          if(vis[i][j] == 1)
            count++;
        }
      }
      return oneCount - count;
    }
};

