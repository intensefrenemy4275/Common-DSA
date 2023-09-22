//link - https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph
class Solution {
  public:
     void dfs(vector<vector<pair<int,int>>> &adj,vector<int> &vis, stack<int> &st, int s)
     {
         vis[s] = 1;
         for(int i=0;i<adj[s].size();i++)
         {
             if(vis[adj[s][i].first] != 1)
             {
                 dfs(adj,vis,st,adj[s][i].first);
             }
         }
         st.push(s);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> adj(N);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
        }
        vector<int> vis(N,0);
        stack<int> st;
        for(int i=0;i<N;i++)
        {
            if(vis[i] == 0)
            {
                dfs(adj,vis,st,i);
            }
        }
        vector<int> minDist(N,1e9);
        minDist[0] = 0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            for(int i=0;i<adj[node].size();i++)
            {
                if(minDist[node] + adj[node][i].second < minDist[adj[node][i].first])
                {
                    minDist[adj[node][i].first] = minDist[node] + adj[node][i].second;
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            if(minDist[i] == 1e9)
                minDist[i] = -1;
        }
        return minDist;
    }
};
