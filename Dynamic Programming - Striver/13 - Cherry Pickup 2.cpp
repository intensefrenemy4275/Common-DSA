class Solution {
public:
    bool valid(int i,int j1, int j2, int m, int n)
    {
        if(i >= 0 && i < m && j1 >= 0 && j2 >= 0 && j1 < n && j2 < n)
        {
            return true;
        }
        return false;
    }
    int solve(int i,int j1, int j2,vector<vector<vector<int>>> &maxCherry, vector<vector<int>>& grid)
    {
        if(i == grid.size() - 1)
        {
            if(j1 == j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        if(maxCherry[i][j1][j2] != INT_MIN) return maxCherry[i][j1][j2];
        int nr = i+1;
        int nj1,nj2;
        int val = INT_MIN;
        for(int k = -1;k<=1;k++)
        {
            for(int l=-1;l<=1;l++)
            {
                nj1 = j1 + k;
                nj2 = j2 + l;
                if(valid(nr,nj1,nj2,grid.size(),grid[0].size()))
                {
                    if(j1 == j2)
                    {
                        val = max(val,grid[i][j1] + solve(nr,nj1,nj2,maxCherry,grid));
                    }
                    else
                    {
                        val = max(val, grid[i][j1] + grid[i][j2] + solve(nr,nj1,nj2,maxCherry,grid));
                    }
                }
            }
        }
        maxCherry[i][j1][j2] = val;
        return val;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> maxCherry(rows,vector<vector<int>>(cols,vector<int>(cols,INT_MIN)));
        return solve(0,0,cols-1,maxCherry,grid);
    }
};