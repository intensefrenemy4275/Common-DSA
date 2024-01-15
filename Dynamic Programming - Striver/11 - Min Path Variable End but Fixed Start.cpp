class Solution {
public:
    int solve(int r, int c, vector<vector<int>>& triangle, vector<vector<int>>& minPath)
    {
        if(r == triangle.size() - 1)
            return triangle[r][c];
        if(minPath[r][c] != INT_MIN)
            return minPath[r][c];
        int ff = triangle[r][c] + solve(r+1,c,triangle,minPath);
        int ss = triangle[r][c] + solve(r+1,c+1,triangle,minPath);
        minPath[r][c] = min(ff,ss);
        return minPath[r][c];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> minPath(triangle.size());
        for(int i = 0;i<triangle.size();i++)
        {
            vector<int> v(triangle[i].size(),INT_MIN);
            minPath[i] = v;
        }
        return solve(0,0,triangle,minPath);
    }
};