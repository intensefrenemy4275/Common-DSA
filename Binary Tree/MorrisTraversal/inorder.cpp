vector<int> inorder(Node* root)
{
  vector<int> ans;
  Node* curr = root;
  while(curr!=NULL)
  {
    if(curr->left == NULL)
    {
        ans.push_back(curr->data);
        curr = curr -> right;
    }
    else
    {
      Node* temp = curr; //to go and check whether left subtree is visited or not
      temp = curr->left;
      while(temp->right!=NULL && temp->next!=curr)
      {
        temp = temp->right;
      }
      if(temp == NULL) //not visited before
      {
        temp->right = curr;
        curr = curr->left;
      }
      else //visited before, remove links
      {
        temp->right = NULL;
        ans.push_back(curr->data); //returned back to curr, store it's data in answer vector
        curr = curr->right;
      }
    }
  }
  return ans;
}
