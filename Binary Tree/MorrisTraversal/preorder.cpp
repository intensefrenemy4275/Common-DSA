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
        ans.push_back(curr->data); //visited for the first time, store current data in answer
        curr = curr->left;
      }
      else //visited before, remove links
      {
        temp->right = NULL;
        curr = curr->right;
      }
    }
  }
  return ans;
}
