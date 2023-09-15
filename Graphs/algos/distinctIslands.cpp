//https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
class Solution {
  public:
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int,int>> &vec, int r0, int c0)
    {
      vec.push_back(make_pair(r-r0,c-c0));
      vis[r][c] = 1;
      int totR = grid.size();
      int totC = grid[0].size();
      int dr[] = {0,0,-1,1};
      int dc[] = {1,-1,0,0};
      for(int i=0;i<4;i++)
      {
        int nrow = r + dr[i];
        int ncol = c + dc[i];
        if(nrow>=0 && nrow<totR && ncol >=0 && ncol<totC  && vis[nrow][ncol] != 1 && grid[nrow][ncol] == 1)
        {
          dfs(nrow,ncol,vis,grid,vec,r0,c0);
        }
      }

    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        set<vector<pair<int,int>>> set;
        for(int i=0;i<grid.size();i++)
        {
          for(int j=0;j<grid[0].size();j++)
          {
            if(vis[i][j] != 1 && grid[i][j] == 1)
            {
              vector<pair<int,int>> vec;
              dfs(i,j,vis,grid,vec,i,j);
              set.insert(vec);
            }
          }
        }
        return set.size();
    }
};
