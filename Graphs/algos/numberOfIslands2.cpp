//link - https://practice.geeksforgeeks.org/problems/number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-islands
#include <iostream>
#include <vector>
using namespace std;
class DisjointSet
{
  vector<int> parent;
  vector<int> rank;
  public:
    DisjointSet(int n)
    {
      parent.resize(n);
      rank.resize(n,0);
      for(int i=0;i<n;i++)
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
      if(rank[ult_v] == rank[ult_u])
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
        parent[ult_v] = ult_u;
      }
    }

    bool check(int u, int v)
    {
      if(findUltimateParent(u) == findUltimateParent(v))
        return true;
      return false;
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
      //vector<vector<int>> matrix(n, vector<int>(m,0));
      DisjointSet ds(n*m);
      int count = 0;
      vector<int> ans;
      vector<vector<int>> vis(n,vector<int>(m,0));
      for(auto it : operators)
      {
        int r = it[0];
        int c = it[1];
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        int oldNode = r*m + c;
        if(vis[r][c] == 1) 
        {
          ans.push_back(count);
          continue;
        }
        vis[r][c] = 1;
        count++;
        for(int i=0;i<4;i++)
        {
          int nrow = r + dr[i];
          int ncol = c + dc[i];
          int newNode = nrow * m + ncol;
          if(nrow>=0 && nrow<n && ncol >= 0 && ncol < m )
          {
            if(vis[nrow][ncol] == 1 && !ds.check(oldNode,newNode))
            {
              ds.unionByRank(oldNode,newNode);
              count--;
            }
          }
        }
        ans.push_back(count);
      }
      return ans;
    }
};
