#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#define ulli unsigned long long int
#define lli long long int
#define pb push_back
#define pii pair<int,int>
#define pib pair<int,bool>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vvs vector<vector<string>>
#define KONECT4 int dx[] = {1,-1,0,0};\
                int dy[] = {0,0,1,-1};
#define KONECT8 int dx[] = {1,-1,0,0,1,1,-1,-1};\
                int dy[] = {0,0,1,-1,1,-1,-1,1};
using namespace std;
void dfs(int node, vvi& adj, int par, vi& parent, int dep, vi& depth)
{
    parent[node] = par;
    depth[node] = dep;
    for(auto i : adj[node])
    {
        if(i != par)
        {
            dfs(i,adj,node,parent,dep+1,depth);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vvi adj(n+1);
    for(int i = 1; i<n ; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    // assume root to be 1
    vvi lift(n+1, vi(20));
    vi parent(n+1);
    vi depth(n+1);
    dfs(1,adj,1,parent,0,depth);
    // binary lifting table
    for(int i = 1; i<=n; i++)
    {
        lift[i][0] = parent[i];
    }
    for(int i = 1; i<20; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            lift[j][i] = lift[lift[j][i-1]][i-1];
        }
    }
    int q;
    cin >> q;
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        // lca of a & b
        int ta = a;
        int tb = b;
        if(depth[b] > depth[a])
        {
            swap(a,b);
            swap(tb, ta);
        }
        // getting both at same depth
        int k = depth[a] - depth[b];
        for(int j = 19; j>= 0 ; j--)
        {
            if(k & (1 << j))
                a = lift[a][j];
        }
        int lca;
        if(a == b)
        {
            lca = a;
        }
        // child of LCA
        for(int j = 19; j>=0; j--)
        {
            if(lift[a][j] != lift[b][j])
            {
                a = lift[a][j];
                b = lift[b][j];
            }
        }
        if(a != b)
            lca = lift[a][0];
        int dist = depth[ta] + depth[tb] - 2 * depth[lca];
        cout << lca << endl;
        cout << dist << endl;
    }
}