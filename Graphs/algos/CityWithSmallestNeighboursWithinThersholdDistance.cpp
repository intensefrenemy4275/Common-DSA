//link- https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=city-with-the-smallest-number-of-neighbors-at-a-threshold-distance
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int tress) 
    {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        int headCount = INT_MAX;
        int city;
        for(int i=0;i<n;i++) //dijkstra on ith node
        {
            vector<int> minDist(n,1e9);
            minDist[i] = 0;
            int cnt = 0;
            set<pair<int,int>> set;
            set.insert({0,i});
            while(!set.empty())
            {
                auto it = *(set.begin());
                set.erase(it);
                int currDist = it.first;
                int node = it.second;
                for(int j=0;j<adj[node].size();j++)
                {
                    int wt = adj[node][j].second;
                    int newNode = adj[node][j].first;
                    if(minDist[node] + wt < minDist[newNode])
                    {
                        if(minDist[newNode] != 1e9)
                            set.erase({minDist[newNode],newNode});
                        minDist[newNode] = minDist[node] + wt;
                        set.insert({minDist[newNode],newNode});
                    }
                }
            }
            for(int l=0;l<n;l++)
            {
                if(minDist[l] <= tress)
                {
                    cnt++;
                }
            }
            if(cnt<=headCount)
            {
                headCount = cnt;
                city = i;
            }
        }
        return city;
    }
};
