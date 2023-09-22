//link - https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree
class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> vis(V,0);
        int sum = 0;
        set<pair<int,int>> set;
        set.insert({0,0});
        while(!set.empty())
        {
            auto it = *(set.begin());
            int currWt = it.first;
            int node = it.second;
            set.erase(it);
            if(vis[node] == 1) continue;
            sum = sum + currWt;
            vis[node] = 1;
            for (auto it : adj[node]) {
				int adjNode = it[0];
				int edW = it[1];
				if (!vis[adjNode]) {
					set.insert({edW, adjNode});
				}
			}
        }
        return sum;
    }
};
