class Solution{
  public:
    void solve(Node* root, int &cumSum, int k, unordered_map<int,int> &map,int &count)
    {
      if(root==NULL)
      {
        return;
      }
      cumSum = cumSum + root->data;
      map[cumSum]++;
      if(root->data == k)
        count++;
      if(cumSum==k)
        count++;
      solve(root->left,cumSum,k,map,count);
      count = count + map[cumSum - k];
      solve(root->right,cumSum,k,map,count);
      map[cumSum]--;
      cumSum =cumSum - root->data;

    }
    int sumK(Node *root,int k)
    {
      int count = 0;
      unordered_map<int,int> map;
      int cumSum = 0;
      solve(root,cumSum,k,map,count);
      return count;
    }
};
