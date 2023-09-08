class Solution
{
public:
    pair<int,int> solve(Node* root)
    {
        if(root == NULL)
        {
          return make_pair(0,0);
        }
        pair<int,int> left =  solve(root->left);
        pair<int,int> right =  solve(root->right);
        int leftH = left.second;
        int rightH = right.second;
        if(leftH > rightH)
        {
          return make_pair(left.first + root->data,leftH + 1);
        }
        else if(rightH > leftH)
        {
          return make_pair(right.first + root->data, rightH+1);
        }
        else
        {
          return make_pair(max(right.first , left.first) + root->data, leftH+1);
        }
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        return solve(root).first;
    }
};
