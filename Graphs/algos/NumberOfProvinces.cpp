class Solution {
  private:
    void bfs(vector<vector<int>> graph,int s, int vis[])
    {
      vis[s] = 1;
      queue<int> q;
      q.push(s);
      while(!q.empty())
      {
        int f = q.front();
        q.pop();
        for(int i=0;i<graph[f].size();i++)
        {
          if(vis[graph[f][i]] != 1)
          {
            q.push(graph[f][i]);
            vis[graph[f][i]] = 1;
          }
        }
      }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        //convert adjacency matrix to list
        vector<vector<int>> graph(V+1);
        for(int i=0;i<V;i++)
        {
          for(int j=0;j<V;j++)
          {
            if(adj[i][j] == 1 && i!=j)
            {
              graph[i+1].push_back(j+1);
            }
          }
        }
        int vis[V+1] = {0};
        int count = 0;
        for(int i=1;i<=V;i++)
        {
            if(vis[i] != 1)
            {
              count++;
              bfs(graph,i,vis);
            }
        }
    return count;

    }
};
