//https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree

class DisjointSet
{
  vector<int> parent;
  vector<int> rank;
  public:
  DisjointSet(int v)
  {
    rank.resize(v,0);
    parent.resize(v);
    for(int i=0;i<v;i++)
    {
      parent[i] = i;
    }
  }

  int findUltimateParent(int node)
  {
    if(node == parent[node])
      return node;

    parent[node] = findUltimateParent(parent[node]);
    return parent[node];
  }

  void unionByRank(int u,int v)
  {
    int ult_u = findUltimateParent(u);
    int ult_v = findUltimateParent(v);
    if(ult_u == ult_v)  return;
    if(rank[ult_u] == rank[ult_v])
    {
      parent[ult_v] = ult_u;
      rank[ult_u]++;
    }
    else if(rank[ult_u] > rank[ult_v])
    {
      parent[ult_v] = ult_u;
    }
    else
    {
      parent[ult_u] = ult_v;
    }
  }

  bool check(int u,int v)
  {
    if(findUltimateParent[u] == findUltimateParent[v])
    {
      return true;
    }
    return false;
  }
};
class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
      vector<pair<int,pair<int,int>>> edges;
      for(int i=0;i<V;i++)
      {
        int f = i;
        for(int j=0;j<adj[i].size();j++)
        {
          int s = adj[i][j][0];
          int wt = adj[i][j][1];
          edges.push_back({wt,{f,s}});
        }
      }
      int ans = 0;
      sort(edges.begin(),edges.end());
      DisjointSet set(V);
      for(auto it:edges)
      {
        int wt = it.first;
        int f = it.second.first;
        int s = it.second.second;
        if(!set.check(f,s))
        {
          ans = ans+wt;
          set.unionByRank(f,s);
        }
      }
      return ans;
    }
};

