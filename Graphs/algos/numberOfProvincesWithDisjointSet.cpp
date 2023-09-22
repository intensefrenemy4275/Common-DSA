//link - https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-provinces
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
    if(findUltimateParent(u) == findUltimateParent(v))
    {
      return true;
    }
    return false;
  }
};
class Solution {
  
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        //convert adjacency matrix to list
        vector<vector<int>> graph(V+1);
        DisjointSet set(V);
        for(int i=0;i<V;i++)
        {
          for(int j=0;j<V;j++)
          {
            if(adj[i][j] == 1 && i!=j)
            {
              set.unionByRank(i,j);
            }
          }
        }
        int count = 0;
        for(int i=0;i<V;i++)
        {
            if(set.findUltimateParent(i) == i)
                count++;
        }
    return count;

    }
};
