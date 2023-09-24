//https://practice.geeksforgeeks.org/problems/account-merge/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=account-merge
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
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
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    DisjointSet ds(accounts.size());
    unordered_map<string,int> map;
    for(int i=0;i<accounts.size();i++)
    {
      for(int j=1;j<accounts[i].size();j++)
      {
        if(map.find(accounts[i][j]) != map.end())
        {
          ds.unionByRank(i,map[accounts[i][j]]);  
          continue;
        }
        map[accounts[i][j]] = i;
      }
    }
    vector<vector<string>> ans;
    unordered_map<int,vector<string>> revMap;
    for(auto it : map)
    { 
      string mail = it.first;
      int idx = ds.findUltimateParent(it.second);
      revMap[idx].push_back(mail);
    }
    for(auto it : revMap)
    {
      sort(it.second.begin(),it.second.end());
      vector<string> temp;
      temp.push_back(accounts[it.first][0]);
      for(int i=0;i<it.second.size();i++)
      {
        temp.push_back(it.second[i]);
      }
      ans.push_back(temp);
    }
    return ans;
    }
    };
