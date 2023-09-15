//link - https://practice.geeksforgeeks.org/problems/eventual-safe-states/1
class Solution {
  public:
    void dfs(vector<int> adj[], vector<int> &vis, int node)
    {
        vis[node] = 2;
        for(int i=0;i<adj[node].size();i++)
        {
            if(vis[adj[node][i]] == 0)
                dfs(adj,vis,adj[node][i]);
            if(vis[adj[node][i]] == 2)
                return;
        }
        vis[node] = 1;
        return;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i] == 0)
            {
                dfs(adj,vis,i);
            }
        }
        for(int i=0;i<V;i++)
        {
            if(vis[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
};
