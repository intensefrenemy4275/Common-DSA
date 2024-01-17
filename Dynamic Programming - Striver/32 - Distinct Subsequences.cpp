class Solution {
public:
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &ways)
    {
        if(j == t.size())
            return 1;
        if(i == s.size())
            return 0;
        if(ways[i][j] != -1) return ways[i][j];
        int notTake = solve(i+1,j,s,t,ways);
        int take = 0;
        if(s[i] == t[j])
        {
            take = solve(i+1,j+1,s,t,ways);
        }
        ways[i][j] = take + notTake;
        return ways[i][j];
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> ways(s.size(),vector<int>(t.size(),-1));
        return solve(0,0,s,t,ways);
    }
};