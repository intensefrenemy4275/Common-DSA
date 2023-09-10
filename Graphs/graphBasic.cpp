#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(int s, vector<vector<int>> graph)
{
  vector<int> visited(graph.size(),0);
  queue<int> q;
  q.push(s);
  visited[s] = 1;
  while(!q.empty())
  {
    int f = q.front();
    q.pop();
    cout<<f<<" ";
    for(int i=0;i<graph[f].size();i++)
    {
      if(visited[graph[f][i]] != 1)
      {
        q.push(graph[f][i]);
        visited[graph[f][i]] = 1;
      }
    }
  }
  cout<<endl<<endl;
}
void dfs(int s,vector<vector<int>> &graph, int vis[])
{
  vis[s] = 1;
  cout<<s<<" ";
  for(int i=0;i<graph[s].size();i++)
  {
    if(vis[graph[s][i]]!=1)
    {
      dfs(graph[s][i],graph,vis);
    }
  }
  return;
}
bool detectCycleBFS(vector<vector<int>> graph, int vis[],int s)
{
  vis[s] = 1;
  queue<pair<int,int>> q;
  q.push(make_pair(s,-1));
  while(!q.empty())
  {
    int node = q.front().first;
    int src = q.front().second;
    q.pop();
    for(int i=0;i<graph[node].size();i++)
    {
      if(vis[graph[node][i]] != 1)
      {
      vis[graph[node][i]] = 1;
      q.push(make_pair(graph[node][i],node));
      }
      else if(graph[node][i] != src)
      {
        return true;
      }
    }
  }
  return false;
}
bool detectCycleDFS(vector<vector<int>> &graph, int vis[], int node, int parent)
{
  vis[node] = 1;
  for(int i=0;i<graph[node].size();i++)
  {
    if(vis[graph[node][i]] != 1)
    {
      bool ans = detectCycleDFS(graph, vis, graph[node][i], node);
      if(ans)
        return true;
    }
    else if(graph[node][i] != parent)
      return true;
  }
  return false;
}
int main()
{
  
  int e;
  cout<<"Edges of Graph : "<<endl;
  cin>>e;
  cout<<"Vertexes : "<<endl;
  int v;
  cin>>v;
  vector<vector<int>> graph(v+1); //1 based indexing
  graph[0].push_back(-1);
  for(int i=0;i<e;i++)
  {
    int l1;
    int l2;
    cout<<"Enter Edge : "<<endl;
    cin>>l1;
    cin>>l2;
    graph[l1].push_back(l2);
    graph[l2].push_back(l1);
    //undirected graph
  }
  bool cycle = false;
  cout<<"Cycle : "<<endl;
  int vis[v+1] = {0};
  for(int i=1;i<=v;i++)
  {
    if(vis[i] == 0 && detectCycleDFS(graph,vis,i,-1))
    {
      cycle = true;
      break;
    }
  }
  cout<<cycle<<endl;
  return 0;
}
