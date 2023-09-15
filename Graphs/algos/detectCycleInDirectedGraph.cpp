//link - https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph
class Solution {
  public:
    bool dfs(vector<int> adj[],vector<int> &vis, vector<int> &visPath, int s)
    {
      vis[s] = 1;
      visPath[s] = 1;
      for(int i=0;i<adj[s].size();i++)
      {
        if(vis[adj[s][i]] == 0)
        {
          bool temp = dfs(adj,vis,visPath,adj[s][i]);
          if(temp)
            return true;
        }
        if(vis[adj[s][i]] == 1 && visPath[adj[s][i]] == 1)
        {
          return true;
        }
      }
      visPath[s] = 0;
      return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> visPath(V,0);
        for(int i=0;i<V;i++)
        {
          if(vis[i] != 1)
          {
            bool temp = dfs(adj,vis,visPath,i);
            if(temp)
              return true;
          }
        }
        return false;
    }
};
