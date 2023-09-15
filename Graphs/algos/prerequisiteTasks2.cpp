//https://practice.geeksforgeeks.org/problems/course-schedule/1
class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        int N = n;
        vector<int> adj[N];
	    for(int i=0;i<prerequisites.size();i++)
	    {
	        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
	    }
	    vector<int> indegree(N,0);
	    for(int i=0;i<N;i++)
	    {
	        for(int j=0;j<adj[i].size();j++)
	        {
	            indegree[adj[i][j]]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<N;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int count = 0;
        vector<int> ans;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            ans.push_back(node);
            for(int i=0;i<adj[node].size();i++)
            {
                indegree[adj[node][i]]--;
                if(indegree[adj[node][i]] == 0)
                {
                    q.push(adj[node][i]);
                }
            }
        }
        if(count == N)
        {
            return ans;
        }
        vector<int> c;
        return c;
	
    }
};
