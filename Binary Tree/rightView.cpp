class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       map<int,int> map; //level to element map
       queue<pair<Node*,int>> q; //Node to level map;
       q.push(make_pair(root,0));
       while(!q.empty())
       {
         Node* frontal = q.front().first;
         int lvl = q.front().second;
         map[lvl] = frontal->data;
         q.pop();
         if(frontal->left)
         {
           q.push(make_pair(frontal->left,lvl+1));
         }
         if(frontal->right)
         {
           q.push(make_pair(frontal->right,lvl+1));
         }
       }
    vector<int> ans;
    for(auto const&p: map)
    {
      ans.push_back(p.second);
    }
    return ans;
    }
};
