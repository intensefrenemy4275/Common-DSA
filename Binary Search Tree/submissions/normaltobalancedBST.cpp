TreeNode<int>* bst(int s, int e, vector<int> &inOrder)
{
    if(s>e)
        return NULL;
    int mid = (s+e)/2; 
    TreeNode<int>* root = new TreeNode<int>(inOrder[mid]);
    root->left = bst(s,mid-1,inOrder);
    root->right = bst(mid+1,e,inOrder);
    return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
  TreeNode<int>* curr = root;
  vector<int> inOrder;
  while(curr!=NULL)
  {
    if(curr->left == NULL)
    {
      inOrder.push_back(curr->data);
      curr = curr->right;
    }
    else
    {
      TreeNode<int>* temp = curr;
      temp = curr->left;
      while(temp->right!=NULL && temp->right!=curr)
      {
        temp = temp->right;
      }
      if(temp->right==NULL)
      {
        temp->right = curr;
        curr = curr->left;
      }
      else
      {
        temp->right = NULL;
        inOrder.push_back(curr->data);
        curr = curr->right;
      }
    }
  }
  return bst(0,inOrder.size()-1,inOrder);
}
