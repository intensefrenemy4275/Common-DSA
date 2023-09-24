//link - https://practice.geeksforgeeks.org/problems/connecting-the-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=connecting-the-graph
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
    int Solve(int n, vector<vector<int>>& edge) {
      DisjointSet ds(n);
      int count = 0;
      for(int i=0;i<edge.size();i++)
      {
        int f = edge[i][0];
        int s = edge[i][1];
        if(ds.check(f,s))
        {
          count++;
          continue;
        }
        ds.unionByRank(f,s);
      }
      int compo = 0;
      for(int i=0;i<n;i++)
      {
        if(ds.findUltimateParent(i) == i)
          compo++;
      }

      if(count>=compo-1)
        return compo-1;
      return -1;
    }
};
