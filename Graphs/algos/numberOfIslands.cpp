//problem link - https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands
void bfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> grid)
{
  vis[r][c] = 1;
  queue<pair<int,int>> q;
  q.push(make_pair(r,c));
  int totalRows = grid.size();
  int totalCols = grid[0].size();
  while(!q.empty())
  {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();
    for(int dr= -1;dr<=1;dr++ )
    {
      for(int dc=-1;dc<=1;dc++)
      {
        int nrow = row + dr;
        int ncol = col + dc;
        if(nrow>=0 && nrow<totalRows && ncol >= 0 && ncol < totalCols && vis[nrow][ncol] != 1 && grid[nrow][ncol] == '1')
        {
          q.push(make_pair(nrow,ncol));
          vis[nrow][ncol] = 1;
        }
      }
    }
  }
}
int numIslands(vector<vector<char>>& grid) 
{
  vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
  int cnt = 0;
  for(int i=0;i<grid.size();i++)
  {
    for(int j=0;j<grid[0].size();j++)
    {
      if(grid[i][j] == '1' && vis[i][j] != 1)
      {
        cnt++;
        bfs(i,j,vis,grid);
      }
    }
  }
  return cnt;
}
