#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int solve(int step, vector<int> &v)
{
    if(step == 0)
    {
        return 1;
    }
    if(step < 0)
        return 0;  
    if(v[step] != -1)
    {
        return v[step];
    }  
    v[step] = solve(step-1,v) + solve(step-2,v);
    return v[step];
}
int main()
{
    int n;
    cin>>n;
    unordered_map<int,int> map;
    vector<int> v(1000,-1);
    int ans = solve(n,v);
    cout<<ans<<endl;
}