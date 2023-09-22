//link - https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=cheapest-flights-within-k-stops
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: flights)
        {
            adj[it[0]].push_back(make_pair(it[1],it[2]));
        }
        set<pair<int,pair<int,int>>> set;
        set.insert({0,{src,0}});
        int ans = INT_MAX;
        while(!set.empty())
        {
            auto it = *(set.begin());
            int currStops = it.first;
            int currCost = it.second.second;
            int node = it.second.first;
            set.erase(it);
            for(int i=0;i<adj[node].size();i++)
            {
                if(currStops == k && adj[node][i].first != dst )
                    continue;
                if(adj[node][i].first == dst)
                {
                    ans = min(ans,currCost + adj[node][i].second);
                    continue;
                }
                // set.insert({currStops+1,{adj[node][i].first,currCost + adj[node][i].second}});
                int stops = currStops + 1;
                int newNode = adj[node][i].first;
                int newPrice = currCost + adj[node][i].second;
                set.insert({stops,{newNode,newPrice}});
            }
        }
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};
