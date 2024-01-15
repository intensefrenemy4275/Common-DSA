class Solution {
public:
    int solve(int r, int c, int m, int n, vector<vector<int>>& grid, vector<vector<int>> &cost)
    {
        if(r == m-1 && c == n-1)
            return grid[r][c];
        if(cost[r][c] != -1)
            return cost[r][c];
        int currAns = INT_MAX;
        if(r+1 < m)
        {
            currAns = min(currAns,grid[r][c] + solve(r+1,c,m,n,grid,cost));
        }
        if(c+1 < n)
        {
            currAns = min(currAns,grid[r][c] + solve(r,c+1,m,n,grid,cost));
        }
        cost[r][c] = currAns;
        return currAns;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> cost(m,vector<int>(n,-1));
        return solve(0,0,m,n,grid,cost);
    }
};