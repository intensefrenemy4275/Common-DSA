BinaryTreeNode<int>* createBST(vector<int> &pre, int &i, int min, int max)
{
  if(i >= pre.size())
  {
    return NULL;
  }
  if(pre[i] > max || pre[i] < min)
  {
    return NULL;
  }

  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(pre[i++]);
  root->left = createBST(pre,i,min,root->data);
  root->right = createBST(pre,i,root->data,max);
  return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
 int min = INT_MIN;
 int max = INT_MAX;
 int idx = 0;
 return createBST(preorder,idx,min,max);
}
