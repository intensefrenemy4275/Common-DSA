#include <iostream>
using namespace std;
int fibo1(int a, int* dp)
{
    if(a <= 1)
        return a;
    if(dp[a] != -1)
        return dp[a];
    dp[a] = fibo1(a-1,dp) + fibo1(a-2,dp);
    return dp[a];
}
int fibo2(int a, int* dp) 
{
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2;i<=a;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[a];
}
int main()
{
    int dp[100] = {0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int pos;
    cin>>pos;
    cout << fibo2(pos,dp) << endl;
    return 0;
}