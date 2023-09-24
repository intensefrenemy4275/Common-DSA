//link - https://practice.geeksforgeeks.org/problems/maximum-connected-group/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-connected-group
class DisjointSet
{
  public : 
  vector<int> parent;
  vector<int> rank;
  vector<int> size;

    DisjointSet(int n)
    {
      parent.resize(n);
      rank.resize(n,0);
      size.resize(n,1);
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
      if(ult_u == ult_v) return;
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
    
    void unionBySize(int u,int v)
    {
      int ult_u = findUltimateParent(u);
      int ult_v = findUltimateParent(v);
      if(ult_u == ult_v) return;
      if(size[ult_u] == size[ult_v])
      {
        parent[ult_u] = ult_v;
        size[ult_v] += size[ult_u];
      }
      
      else if(size[ult_u] > size[ult_v])
      {
        parent[ult_v] = ult_u;
        size[ult_u] += size[ult_v];
      }

      else
      {
        parent[ult_u] = ult_v;
        size[ult_v] += size[ult_u];
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
    private:
    bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        // vector<vector<int>> vis(n,vector<int>(n,0));
        bool z = false;
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<n;j++)
          {
            if(grid[i][j] == 0)
            {
              z = true;
              continue;
            }
            //   vis[i][j] = 1;
              int node = i*n+j;
              int dr[] = {0,0,-1,1};
              int dc[] = {-1,1,0,0};
              int r = i;
              int c = j;
              for(int i=0;i<4;i++)
              {
                int nrow = r + dr[i];
                int ncol = c + dc[i];
                int newNode = nrow * n + ncol;
                if(nrow>=0 && nrow<n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1)
                {
                //   vis[nrow][ncol] = 1;
                  ds.unionBySize(node,newNode);
                }
              }
          }
        }
        
        if(!z)
          return n*n;

        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n)) {
                        if (grid[newr][newc] == 1) {
                            components.insert(ds.findUltimateParent(newr * n + newc));
                        }
                    }
                }
                int sizeTotal = 1;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal);
            }
        }
        
        return mx;
      }
};
