#include <iostream>
#include <queue>
using namespace std;
class Node
{
  public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
      this->data = data;
      this->left = NULL;
      this->right = NULL;
    }
};
Node* insertNode(int data, Node* root)
{
  if(root == NULL)
  {
    Node* temp = new Node(data);
    return temp;
  }

  if(root->data > data)
  {
    root->left =  insertNode(data,root->left);
    return root;
  }
  else
  {
    root->right = insertNode(data,root->right);
    return root;
  }
}
void inputData(Node* root)
{
  int d;
  cin>>d;
  while(d!=-1)
  {
    insertNode(d,root);
    cin>>d;
  }
}
int minVal(Node* root)
{
  Node* temp = root;
  while(temp->left!=NULL)
  {
    temp = temp->left;
  }
  return temp->data;
}
int maxVal(Node* root)
{
  Node* temp = root;
  while(temp->right!=NULL)
  {
    temp = temp->right;
  }
  return temp->data;
}
Node* deleteNode(Node* root, int data)
{
  if(root == NULL)
  {
    cout<<"Does not exist"<<endl;
    return root;
  }
  if(root->data == data)
  {
    //no child
    if(root->left == NULL && root->right == NULL)
    {
      delete root;
      return NULL;
    }
    //1 child
    //left child
    if(root->left != NULL && root->right == NULL)
    {
      Node* temp = root->left;
      delete root;
      return temp;
    }
    //right child
    if(root->left == NULL && root->right!=NULL)
    {
      Node* temp = root->right;
      delete root;
      return temp;
    }
    //both children present
    if(root->left != NULL && root->right != NULL)
    {
      int mini = minVal(root->right);
      root ->data = mini;
      root->right = deleteNode(root->right,mini);
    }
  }
  else
  {
    if(root->data > data)
    {
      root->left = deleteNode(root->left,data);
      return root;
    }
    else
    {
      root->right = deleteNode(root->right,data);
      return root;
    }
  }
}
void levelOrderTraversal(Node* root)
{
  queue<Node*> q;
  q.push(root);
  while(!q.empty())
  {
    int n = q.size();
    for(int i=0;i<n;i++)
    {
      cout<<q.front()->data<<" ";
      if(q.front() -> left)
      {
        q.push(q.front() -> left);
      }
      if(q.front() -> right)
      {
        q.push(q.front() ->right);
      }
      q.pop();
    }
    cout<<endl;
  }
}
void inOrder(Node* root)
{
  if(root == NULL)
  {
    return;
  }
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}
int main()
{
int a;
cin>>a;
Node* root = new Node(a);
inputData(root);
inOrder(root);
cout<<endl<<endl;
int r;
cin>>r;
deleteNode(root,r);
inOrder(root);

}

