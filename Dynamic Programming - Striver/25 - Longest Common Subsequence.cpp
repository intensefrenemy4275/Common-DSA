// Tabulation Solution : (Memoization hits TLE on LC)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> lcs(text1.size()+1,vector<int>(text2.size()+1,0)); //indexes shifted
        // base case is already met because all values are set to 0
        for(int i = 1;i<=text1.size();i++)
        {
            for(int j=1;j<=text2.size();j++)
            {
                if(text1[i-1] == text2[j-1]) // match
                {
                    lcs[i][j] = 1 + lcs[i-1][j-1];
                }
                else // did not match
                {
                    lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
                }
            }
        }
        return lcs[text1.size()][text2.size()];
      
    }
};
// Memoization Solution : 
int solve(int i, int j, string text1, string text2, vector<vector<int>> &lcs)
    {
        if(i < 0 || j < 0)
            return 0;
        if(lcs[i][j] != -1 ) return lcs[i][j];
        if(text1[i] == text2[j]) // match
        {
            lcs[i][j] = 1 + solve(i-1,j-1,text1,text2,lcs);
        }
        else // not match
        {
            lcs[i][j] = max(solve(i-1,j,text1,text2,lcs), solve(i,j-1,text1,text2,lcs));
        }
        return lcs[i][j];
    }
int lcs(string text1, string text2)
{
	vector<vector<int>> lcs(text1.size(),vector<int>(text2.size(),-1));
        return solve(text1.size()-1,text2.size()-1,text1,text2,lcs);
}