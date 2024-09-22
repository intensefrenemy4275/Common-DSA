//aim to check whether 2 nodes are from same components or not in O(1) time
#include <iostream>
#include <vector>
using namespace std;
class DisjointSet
{
  public:
  vector<int> rank;
  vector<int> parent;
  vector<int> size;
  DisjointSet(int n)
  {
    rank.resize(n+1,0);
    parent.resize(n+1);
    size.resize(n+1,1);
    for(int i=1;i<n+1;i++)
    {
      parent[i] = i;
    }
  }

  int findUltimateParent(int node)
  {
    if(node == parent[node])
    {
      return node;
    }

    parent[node] = findUltimateParent(parent[node]);
    return parent[node];
  }

  void unionByRank(int u, int v)
  {
    int ultimate_u = findUltimateParent(u);
    int ultimate_v = findUltimateParent(v);
    if(ultimate_u == ultimate_v) return;
    if(rank[ultimate_u] == rank[ultimate_v])
    {
      parent[ultimate_v] = ultimate_u;
      rank[ultimate_u]++;
    }
    else if(rank[ultimate_u] > rank[ultimate_v])
    {
      parent[ultimate_v] = ultimate_u;
    }
    else
    {
      parent[ultimate_u] = ultimate_v;
    }
  }

  void unionBySize(int u,int v)
  {
    int ultimate_u = findUltimateParent(u);
    int ultimate_v = findUltimateParent(v);
    if(ultimate_v == ultimate_u)  return;
    if(size[ultimate_u] == size[ultimate_v])
    {
      parent[ultimate_v] = ultimate_u;
      size[ultimate_u] *= 2;
    }
    else if(size[ultimate_u] > size[ultimate_v])
    {
      parent[ultimate_v] = ultimate_u;
      size[ultimate_u] += size[ultimate_v];
    }
    else
    {
      parent[ultimate_u] = ultimate_v;
      size[ultimate_v] += size[ultimate_u];
    }
  }

  bool checkCompo(int u,int v)
  {
    if(findUltimateParent(u) == findUltimateParent(v))
    {
      return true;
    }
    return false;
  }
};

int main()
{
  int size;
  cin>>size;
  DisjointSet ds(size);
  int n1;
  int n2;
  cin>>n1>>n2;
  while(n1!=n2)
  {
    ds.unionBySize(n1,n2);
    cin>>n1;
    cin>>n2;
  }
  cout<<"Run Checks : "<<endl;
  cin>>n1;
  cin>>n2;
  while(n1!=n2)
  {
    cout<<ds.checkCompo(n1,n2)<<endl;
    cin>>n1;
    cin>>n2;
  }
  cout<<endl;
  return 0;
}
