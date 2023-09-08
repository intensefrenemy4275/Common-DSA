class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	queue<Node*> currQueue;
      bool ltr = true;
      currQueue.push(root);
      vector<int> ans;
      ans.push_back(root);
      while(!currQueue.empty())
      {
          vector<int> temp(currQueue.size());
          int n = currQueue.size();
          for(int i =0;i<n;i++)
          {
              if(ltr)
              {
                  temp[i] = currQueue.front()->data;
              }
              else
              {
                  temp[n-1-i] = currQueue.front()->data;
              }
              if(currQueue.front() -> left != NULL)
              {
                  currQueue.push(currQueue.front()->left);
              }
              if(currQueue.front()->right !=NULL)
              {
                  currQueue.push(currQueue.front()->right);
              }
              currQueue.pop();
          }
          ltr = !ltr;
          for(int i=0;i<n;i++)
          {
            ans.push_back(temp[i]);
          }
      }
    return ans;
    }
};
