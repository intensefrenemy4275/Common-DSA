pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int pred = -1;
    int succ = -1;
    TreeNode* temp = root;
    while(temp!=NULL && temp->data != key)
    {
        if(temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }
        else if(temp->data < key)
        {
            pred = temp->data;
            temp = temp->right;
        }
    }
    if(temp!=NULL)
    {
        TreeNode* left = temp->left;
    TreeNode* right = temp->right;
    while(left!=NULL)
    {
        pred = left->data;
        left = left->right;
    }
    while(right!=NULL)
    {
        succ = right->data;
        right = right->left;
    }
    
    }
    pair<int,int> ans = make_pair(pred,succ);
    return ans;
    
}
