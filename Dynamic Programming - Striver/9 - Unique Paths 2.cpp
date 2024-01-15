class Solution {
public:
    int solve(int r, int c, int m, int n, vector<vector<int>> &paths, vector<vector<int>>& obstacleGrid)
    {
        if(r >= m || c >= n) return 0;
        if(r == m-1 && c == n-1 && obstacleGrid[r][c] == 0) return 1;
        if(paths[r][c] != -1) return paths[r][c];
        if(obstacleGrid[r][c] == 1)
        {
            paths[r][c] = 0;
            return 0;
        }
        int ff = solve(r+1,c,m,n,paths,obstacleGrid);
        int ss = solve(r,c+1,m,n,paths,obstacleGrid);
        paths[r][c] = ff + ss;
        return ff + ss;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> paths(m, vector<int>(n,-1));
        return solve(0,0,m,n,paths,obstacleGrid);
    }
};