vector<int> mergeArrays( vector<int> v1, vector<int> v2)
{
  int i = 0;
  int j = 0;
  vector<int> ans;
  int n1 = v1.size();
  int n2 = v2.size();
  while(i<n1 && j<n2)
  {
    if(v1[i] < v2[j])
    {
      ans.push_back(v1[i]);
      i++;
    }
    else
    {
      ans.push_back(v2[j]);
      j++;
    }
  }

  while(i<n1)
  {
    ans.push_back(v1[i]);
    i++;
  }
  
  while(j<n2)
  {
    ans.push_back(v2[j]);
    j++;
  }
  return ans;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
  vector<int> inOrder1;
  TreeNode* curr = root1;
  while(curr!=NULL)
  {
    if(curr->left==NULL)
    {
      inOrder1.push_back(curr->data);
      curr = curr->right;
    }
    else
    {
      TreeNode* temp = curr;
      temp = curr->left;
      while(temp->right && temp->right!=curr)
      {
        temp = temp->right;
      }
      if(temp->right == NULL)
      {
        temp->right = curr;
        curr = curr->left;
      }
      else
      {
        temp->right = NULL;
        inOrder1.push_back(curr->data);
        curr = curr->right;
      }
    }
  }
  curr = root2;
  vector<int> inOrder2;
  while(curr!=NULL)
  {
    if(curr->left==NULL)
    {
      inOrder2.push_back(curr->data);
      curr = curr->right;
    }
    else
    {
      TreeNode* temp = curr;
      temp = curr->left;
      while(temp->right && temp->right!=curr)
      {
        temp = temp->right;
      }
      if(temp->right == NULL)
      {
        temp->right = curr;
        curr = curr->left;
      }
      else
      {
        temp->right = NULL;
        inOrder2.push_back(curr->data);
        curr = curr->right;
      }
    }
  }
  vector<int> merged = mergeArrays(inOrder1,inOrder2);
  return merged; 
}
