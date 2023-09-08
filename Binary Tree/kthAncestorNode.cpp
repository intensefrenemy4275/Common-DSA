Node* solve(Node* root,int &k,int target)
{
  if(root==NULL)
  {
    return NULL;
  }
  if(root->data == target)
  {
    return root;
  }
  Node* left = solve(root->left,k,target);
  Node* right = solve(root->right,k,target);
  if(left == NULL && right == NULL)
  {
    return NULL;
  }
  if(left !=NULL && right == NULL)
  {
      k--;
      if(k==0)
      {
        return root;
      }
      return left;
  }
  else
  {
    k--;
    if(k==0)
    {
      return root;
    }
    return right;
  }
}
int kthAncestor(Node *root, int k, int node)
{
   Node* ans = solve(root,k,node);
   if(ans == NULL || ans->data == node)
   {
     return -1;
   }
   return ans->data;
}
