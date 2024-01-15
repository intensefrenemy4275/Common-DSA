#include <bits/stdc++.h> 
int solve(int r, int c, int m, int n, vector<vector<int>> &map)
{
	if(r >= m || c >= n) return 0;
	if(r == m-1 && c == n-1) return 1;
	if(map[r][c] != -1)
	{
		return map[r][c];
	}
	int ff = solve(r+1,c,m,n,map);
	int ss = solve(r,c+1,m,n,map);
	map[r][c] = ff + ss;
	return ff + ss;
}
int uniquePaths(int m, int n) {
	vector<vector<int>> map(m,vector<int>(n,-1));
	int a = solve(0,0,m,n,map);
	return a;
}