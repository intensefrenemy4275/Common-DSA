class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i = 1; i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int i = n; int j = m;
        string scs = "";
        while(i >= 1 && j >= 1)
        {
            if(str1[i-1] == str2[j-1])
            {
                scs = str1[i-1] + scs;
                i--;j--;
            }
            else
            {
                if(dp[i-1][j] > dp[i][j-1])
                {
                    scs = str1[i-1]  + scs;
                    i--;
                }
                else 
                {
                    scs = str2[j-1] + scs;
                    j--;
                }
            }
        }
        if(i == 0 && j != 0)
        {
            while(j!=0)
            {scs = str2[j-1] + scs; j--;}
        }
        if(j == 0 && i != 0)
        {   while(i!=0)
            {scs = str1[i-1] + scs;i--;}
        }
        return scs;
    }
};