class Solution{
  public:
    pair<int,int> solve(Node* root)
    {
      if(root == NULL)
      {
        return make_pair(0,0);
      }
      pair<int,int> left = solve(root->left);
      pair<int,int> right = solve(root->right);
      pair<int,int> answer;
      answer.first = root->data + left.second + right.second;
      answer.second = max(left.first,left.second) + max(right.first,right.second);
      return answer;
    }
    int getMaxSum(Node *root) 
    {
      return max(solve(root).first,solve(root).second);
    }
};
