class Solution
{
    public:
    void flatten(Node *root)
    {
      Node* curr = root;
        while(curr!=NULL)
        {
          if(curr->left==NULL)
          {
            curr = curr -> right;
          }
          else
          {
            Node* temp = curr;
            temp = curr -> left;
            while(temp->right!=NULL)
            {
              temp = temp->right;
            }
            temp->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
            curr = curr->right;
          }
        }
    }
};
