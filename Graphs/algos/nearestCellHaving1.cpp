//link - https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
public:
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	  vector<vector<int>> ans(grid.size(),vector<int>(grid[0].size(),0));
    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
    for(int i = 0;i<grid.size();i++)
    {
      for(int j = 0;j<grid[0].size();j++)
      {
        if(grid[i][j] == 1)
        {
          vis[i][j] = 1;
          ans[i][j] = 0;
          q.push(make_pair(make_pair(i,j),0));
        }
      }
    }
    int totR = grid.size();
    int totC = grid[0].size();
    while(!q.empty())
    {
      int r = q.front().first.first;
      int c = q.front().first.second;
      int dist = q.front().second;
      int dr[] = {-1,1,0,0};
      int dc[] = {0,0,-1,1};
      q.pop();
      for(int i=0;i<4;i++)
      {
        int nrow = r + dr[i];
        int ncol = c + dc[i];
        if(nrow>=0 && nrow<totR && ncol>=0 && ncol<totC && vis[nrow][ncol] != 1 && grid[nrow][ncol] == 0)
        {
          vis[nrow][ncol] = 1;
          q.push(make_pair(make_pair(nrow,ncol),dist+1));
          ans[nrow][ncol] = dist+1;
        }
      }
    }
    return ans;
    
	}
};
