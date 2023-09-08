void inorder(TreeNode<int>*  root, vector<int> &ans){

    if(root==NULL){

        return ;

    }

    inorder(root->left,ans);

    ans.push_back(root->data);

     inorder(root->right,ans);

}

TreeNode<int>* flatten(TreeNode<int>* root)

{

    // Write your code here

     vector<int> ans;

    inorder(root,ans);

    root=new TreeNode<int>(ans[0]);

     TreeNode<int>* curr=root;

    for(int i=1;i<ans.size();i++){

        TreeNode<int>* temp=new TreeNode<int>(ans[i]);

        curr->right=temp;

        curr->left=NULL;

        curr=temp;

    }

    curr->right=NULL;

    curr->left=NULL;

    return root;
}
