class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int,int> map;
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));
        while(!q.empty())
        {
            Node* frontal = q.front().first;
            int hd = q.front().second;
            q.pop();
            if(map.find(hd) == map.end()) //does not exists
              {
                map[hd] = frontal->data;
              }
            if(frontal->left)
            {
                q.push(make_pair(frontal->left,hd-1));
            }
            if(frontal->right)
            {
                q.push(make_pair(frontal->right,hd+1));
            }
        }
        vector<int> ans;
        for(auto const&p : map)
        {
            ans.push_back(p.second);
        }
      return ans;
    }

};
