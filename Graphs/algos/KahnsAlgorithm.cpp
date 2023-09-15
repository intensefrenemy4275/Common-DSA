//link - https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort
class Solution
{
	public:
	//kahn's algorithm
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(int j=0;j<adj[i].size();j++)
	        {
	            indegree[adj[i][j]]++;
	        }
	    }
	    queue<int> q;
	    vector<int> ans;
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        for(int i=0;i<adj[node].size();i++)
	        {
	            indegree[adj[node][i]]--;
	            if(indegree[adj[node][i]] == 0)
	                q.push(adj[node][i]);
	        }
	    }
	    return ans;
	}
};
