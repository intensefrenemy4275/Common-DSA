class Solution {
public:
    int solve(int i, int j, string &word1, string &word2, vector<vector<vector<int>>> &ways, int prev)
    {
        if(j == word2.size())
        {
            return word1.size() - i;
        }
        if(i == word1.size())
        {
            return word2.size() - j;
        }
        if(ways[i][j][prev] != -1) return ways[i][j][prev];
        if(word1[i] == word2[j]) // match
        {
            ways[i][j][prev] = solve(i+1,j+1,word1,word2,ways,0);
        }
        else // did not match
        {
            int replace = 1 + solve(i+1,j+1,word1,word2,ways,1);
            int remove = 1 + solve(i+1,j,word1,word2,ways,2);
            int insert = 1 + solve(i,j+1,word1,word2,ways,3);
            ways[i][j][prev] = min(replace,min(remove,insert));
        }
        return ways[i][j][prev];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<vector<int>>> ways(n,vector<vector<int>>(m,vector<int>(4,-1)));
        return solve(0,0,word1,word2,ways,0);
    }
};