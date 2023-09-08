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
  cout<<"Breadth First Traversal For : "<<endl;
  int start;
  cin>>start;
  cout<<"BFS : "<<endl;
  bfs(start,graph);
  return 0;
}
