//link - https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1
class Solution{
public:
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> &mat)
    {
      vis[r][c] = 1;
      int dr[] = {0,0,-1,1};
      int dc[] = {1,-1,0,0};
      int totR = mat.size();
      int totC = mat[0].size();
      for(int i=0;i<4;i++)
      {
        int nrow = r + dr[i];
        int ncol = c + dc[i];
        if(nrow>=0 && nrow<totR && ncol >=0 && ncol<totC && vis[nrow][ncol] != 1 && mat[nrow][ncol] == 'O')
        {
          dfs(nrow,ncol,vis,mat);
        }
      }
      return;
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(mat.size(),vector<int>(mat[0].size(),0));
        int rowTrav[] = {0,n-1};
        int colTrav[] = {0,m-1};
        //boundary rows --> 0th and n-1th index
        for(int i=0;i<=1;i++)
        {
          int row = rowTrav[i];
          for(int j=0;j<mat[0].size();j++)
          {
            if(mat[row][j] == 'O' && vis[row][j] != 1)
            {
              dfs(row,j,vis,mat);
            }
          }
        }

        for(int i=0;i<2;i++)
        {
          int col = colTrav[i];
          for(int j=0;j<mat.size();j++)
          {
            if(mat[j][col] == 'O' && vis[j][col] != 1 )
            {
              dfs(j,col,vis,mat);
            }
          }
        }
        vector<vector<char>> ans(mat.size(),vector<char>(mat[0].size()));
        for(int i=0;i<mat.size();i++)
        {
          for(int j=0;j<mat[0].size();j++)
          {
            if(vis[i][j] == 0)
            {
              ans[i][j] = 'X';
            }
            else
            {
              ans[i][j] = 'O';
            }
          }
        }
    return ans;
    }
};
