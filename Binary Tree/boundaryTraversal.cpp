class Solution {
public:
    void leftTraverse(Node* root, vector<int> &ans)
    {
      if(root == NULL || root->left == NULL && root->right==NULL) //leaf node or NULL)
      {
        return;
      }

      ans.push_back(root->data);
      leftTraverse(root->left,ans);
      if(root->left == NULL)
      {
        leftTraverse(root->right,ans);
      }
    }
    void leafTraverse(Node* root, vector<int> &ans)
    {
        if(root==NULL)
        {
          return;
        }
        if(root->left == NULL && root -> right == NULL) //leaf node
        {
          ans.push_back(root->data);
        }
        leafTraverse(root->left,ans);
        leafTraverse(root->right,ans);
    }
    void rightTraverse(Node* root, vector<int> &ans)
    {
        if(root == NULL || root->right == NULL && root->left==NULL)
        {
            return;
        }
        rightTraverse(root->right,ans);
        if(root->right==NULL) // or just push back the root-> data first and then lefttraverse only root->left :)
        {
          rightTraverse(root->left,ans);
        }
        ans.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root==NULL)
        {
            return ans;
        }
        if(root->left == NULL)
        {
            ans.push_back(root->data);
            leafTraverse(root->right,ans);
            rightTraverse(root->right,ans);
            return ans;
        }
        leftTraverse(root,ans);
        leafTraverse(root->left,ans);
        leafTraverse(root->right,ans);
        rightTraverse(root->right,ans);
        return ans;
    }
};
