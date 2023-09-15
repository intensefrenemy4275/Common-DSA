//link - https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph
class Solution {
public:
  int opposite(int i) {
    return (i == 0) ? 1 : 0;
}
bool checkDFS(int start , vector<int> &vis,vector<int>adj[],int color)
    {
      vis[start] = color;
      for(int i=0;i<adj[start].size();i++)
      {
          if(vis[adj[start][i]] == -1)
          {
              bool temp = check(adj[start][i],vis,adj,opposite(color));
              if(!temp)
                return false;
          }
          else if(vis[adj[start][i]] == color)
            return false;
      }
      return true;
    }
    bool checkBFS(int start , vector<int> &vis,vector<int>adj[])
    {
    //   vector<int> vis(V,-1);
      queue<pair<int,int>> q;
      q.push(make_pair(start,0));
      vis[start] = 0;
      while(!q.empty())
      {
        int currColor = q.front().second;
        int node = q.front().first;
        q.pop();
        for(int i = 0;i<adj[node].size();i++)
        {
            if(vis[adj[node][i]] == -1 )
            {
              vis[adj[node][i]] = opposite(currColor);
              q.push(make_pair(adj[node][i],vis[adj[node][i]]));
            }
            if(vis[adj[node][i]] == currColor)
            {
              return false;
            }
        }
      }
      return true;  
    }
	bool isBipartite(int V, vector<int>adj[]){
	   // int start = 0;
      vector<int> vis(V,-1);
      for(int i=0;i<vis.size();i++)
      {
          if(vis[i] == -1)
          {
              bool a = check(i,vis,adj);
              if(!a)
              {
                  return false;
              }
          }
      }
      return true;
	}

};
