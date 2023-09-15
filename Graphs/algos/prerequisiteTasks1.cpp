//https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[N];
	    for(int i=0;i<prerequisites.size();i++)
	    {
	        adj[prerequisites[i].second].push_back(prerequisites[i].first);
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
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for(int i=0;i<adj[node].size();i++)
            {
                indegree[adj[node][i]]--;
                if(indegree[adj[node][i]] == 0)
                {
                    q.push(adj[node][i]);
                }
            }
        }
        return count == N;
	}
};
