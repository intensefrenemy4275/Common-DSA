#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k;
int solve(int step, unordered_map<int,int> &map,vector<int> &arr)
{
    if(step == 0)
        return 0;
    if(map.find(step) != map.end())
    {
        return map[step];
    }
    int temp = 1e9;
    for(int i = 1; i<=k;i++)
    {
        if(step - i >= 0)
        {
            temp = min(temp, solve(step - i, map, arr) + abs(arr[step] - arr[step - i]));
        }
    }
    map[step] = temp;
    return map[step];
}
int main()
{
    cin>>n>>k;
    vector<int> stones(n);
    for(int i=0;i<n;i++)
    {
        cin>>stones[i];
    }
    unordered_map<int,int> map;
    int ans = solve(n-1,map,stones);
    cout << ans << endl;
    return 0;
}