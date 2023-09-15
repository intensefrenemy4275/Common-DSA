//link - https://practice.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alien-dictionary
class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        for(int i=0;i<N-1;i++)
        {
            int j = 0;
            int maxi = min(dict[i].length(),dict[i+1].length());
            while(j<maxi)
            {
                if(dict[i][j] != dict[i+1][j])
                {
                    adj[dict[i][j] - 'a'].push_back(dict[i+1][j] - 'a');
                    break;
                }
                j++;
            }
        }
        vector<int> indegree(K,0);
        for(int i=0;i<K;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                indegree[adj[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=0;i<K;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        string ans = "";
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back((char)(node + (int)'a'));
            for(int i=0;i<adj[node].size();i++)
            {
                indegree[adj[node][i]]--;
                if(indegree[adj[node][i]] == 0)
                {
                    q.push(adj[node][i]);
                }
            }
            
        }
        return ans;
    }
};
