#include <bits/stdc++.h>
int solve(int day,int last, map<pair<int,int>, int> &map, vector<vector<int>> &points)
{
    if(day >= points.size())
        return 0;
    // if(day == 0)
    // {
    //     int f = points[0][0] + solve(1,0,map,points);
    //     int s = points[0][1] + solve(1,1,map,points);
    //     int t = points[0][2] + solve(1,2,map,points);
    //     return max(f,max(s,t));
    // }
    if(map.find({day,last}) != map.end())
    {
        return map[{day,last}];
    }
    int maxi = 0;
    for(int i=0;i<=2;i++)
    {
        if(i == last) continue;
        maxi = max(maxi,points[day][i] + solve(day+1,i,map,points));
    }
    map[{day,last}] = maxi;
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
   map<pair<int,int>, int> map;
   return solve(0,-1,map,points);
}