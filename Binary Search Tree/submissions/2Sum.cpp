void inOrder(BinaryTreeNode<int>* root,vector<int> &t)
{
  if(root==NULL)
  {
    return;
  }

  inOrder(root->left,t);
  t.push_back(root->data);
  inOrder(root->right,t);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) 
{
  vector<int> traversal;
  inOrder(root,traversal);
  int i = 0;
  int j = traversal.size()-1;
  while(i<j)
  {
    if(traversal[i] + traversal[j] == target)
      return true;

    if(traversal[i] + traversal[j] > target)
      j--;

    else
      i++;
  }
  return false;
}
