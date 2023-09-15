//link - https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort
class Solution
{
	public:
	void dfs(vector<int> adj[],vector<int> &vis,stack<int> &st, int node)
	{
	    vis[node] = 1;
	    for(int i=0;i<adj[node].size();i++)
	    {
	        if(vis[adj[node][i]] == 0)
	        {
	            dfs(adj,vis,st,adj[node][i]);
	        }
	    }
	    st.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> st;
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]  == 0)
	        {
	            dfs(adj,vis,st,i);
	        }
	    }
	    vector<int> ans;
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};
