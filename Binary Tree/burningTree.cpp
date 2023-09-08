class Solution {
  public:
    Node* mapping(unordered_map<Node*,Node*> &map,int target,Node* root)
    {
      Node* res = NULL;
      queue<Node*> q;
      q.push(root);
      map[root] = NULL;
      while(!q.empty())
      {
        Node* frontal = q.front();
        q.pop();
        if(frontal->data == target)
        {
          res = frontal;
        }
        if(frontal->left)
        {
          map[frontal->left] = frontal;
          q.push(frontal->left);
        }
        if(frontal->right)
        {
          map[frontal->right] = frontal;
          q.push(frontal->right);
        }
      }
    return res;

    }
    int minTime(Node* root, int target)
    {
      unordered_map<Node*,Node*> parent;
      Node* burn = mapping(parent,target,root);
      int ans = 0;
      queue<Node*> q;
      unordered_map<Node*,bool> set;
      q.push(burn);
      int i=0;
      while(!q.empty())
      {
        bool jalaya = false;
        int n = q.size();
        for(int i=0;i<n;i++)
        {
          set[q.front()] = 1;
          Node* curr = q.front();
          if(curr->left!=NULL  && !set[curr->left])
          {
            jalaya = true;
            q.push(curr->left);
            set[curr->left] = 1;
          }
          if(curr->right!=NULL && !set[curr->right])
          {
            jalaya = true;
            q.push(curr->right);
            set[curr->right] = 1;
              
          }
          if(parent[curr]!=NULL && !set[parent[curr]])
          {
            jalaya = true;
            q.push(parent[curr]);
            set[parent[curr]] = 1;
          }
          q.pop();
        }
        if(jalaya)
        {
            ans++;
        }
      }

return ans;
    }
};
