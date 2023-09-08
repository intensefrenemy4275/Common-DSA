//dont track levels as in level order traversal levels are automatically increasing
//and you are already going left to right in each level , so just maintain horizontal distance
//and map would keep everything sorted :)
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int,vector<int>> hdmap;
        queue<pair<Node*,pair<int,int>>> q;
        vector<int> ans;
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty())
        {
            Node* frontal = q.front().first;
            int hd = q.front().second.first;
            int lvl = q.front().second.second;
            hdmap[hd].push_back(frontal->data);
            q.pop();
            if(frontal->left)
            {
              q.push(make_pair(frontal->left,make_pair(hd-1,lvl+1)));
            }
            if(frontal->right)
            {
              q.push(make_pair(frontal->right,make_pair(hd+1,lvl+1)));
            }

        }
        for(auto const&p: hdmap)
        {
            for(int i=0;i<p.second.size();i++)
            {
                ans.push_back(p.second[i]);
            }
        }
      return ans;
    }
};
