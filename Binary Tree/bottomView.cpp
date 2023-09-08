//bottom most elements for same hd --> only lateral one in level order traversal 
class Solution {
  public:
    vector <int> bottomView(Node *root) {
       map<int,int> map; //horizontal distance map
       queue<pair<Node* , int>> q;
       q.push(make_pair(root,0));
       while(!q.empty())
       {
         Node* frontal = q.front().first;
         int hd = q.front().second;
         map[hd] = frontal->data;
         q.pop();
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
       for(auto const&p: map)
       {
          ans.push_back(p.second);
       }
      return ans;

    }
};
