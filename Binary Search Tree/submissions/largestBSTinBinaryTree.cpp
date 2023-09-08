class info
{
  public:
    int mini;
    int maxi;
    int size;
    bool isBST;
};
info solve(TreeNode* root,int &maxAns)
{
  if(root == NULL)
  {
    return {INT_MAX,INT_MIN,0,true};
  }

  info left = solve(root->left,maxAns);
  info right = solve(root->right,maxAns);
  info currAns;
  currAns.maxi = max(right.maxi,root->data);
  currAns.mini = min(left.mini,root->data);
  currAns.size = left.size + right.size + 1;
  if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
  {
      currAns.isBST = true;
  }

  else
  {
      currAns.isBST = false;
  }

  if(currAns.isBST)
  {
      maxAns = max(maxAns,currAns.size);
  }

  return currAns;
}
int largestBST(TreeNode * root){
     int answer = 0;
     solve(root,answer);
     return answer;
}
