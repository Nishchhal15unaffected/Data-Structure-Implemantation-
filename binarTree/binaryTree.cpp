#include<iostream>
#include<queue>
#include "binaryTreeNode.cpp"
using namespace std;
//take input by recursion
binaryTreeNode<int>* takeInput()
{

    int root_data;
    cout<<"enter the data";
    cin>>root_data;
    if(root_data==-1)
    {
        return 0;
    }
    binaryTreeNode<int> *root=new binaryTreeNode<int>(root_data);
            binaryTreeNode<int> *leftchild =takeInput();
             binaryTreeNode<int> *rightchild=takeInput();
             root->left=leftchild;
             root->right=rightchild;

}
//print by recursion
void print(binaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<":"<<endl;
    if(root->left!=0)
    {
        cout<<"left value of"<<root->data<<"is"<<root->left->data<<endl;

    }
    if(root->right!=0)
    {
        cout<<"right value of"<<root->data<<"is"<<root->right->data<<endl;
    }
    print(root->left);
    print(root->right);
}
//take input by queue
binaryTreeNode<int>* takeInputLevelWise()
{
    cout<<"enter the root data";
    int root_data;
    cin>>root_data;
    binaryTreeNode<int>*root=new binaryTreeNode<int>(root_data);
    queue<binaryTreeNode<int>*> pandingnode;
    pandingnode.push(root);
    while(pandingnode.size()!=NULL)
    {
        binaryTreeNode<int>*front=pandingnode.front();
        pandingnode.pop();
        cout<<"enter the left node of"<<front->data<<endl;
        int leftnode;
        cin>>leftnode;
        if(leftnode!=-1)
        {
            binaryTreeNode<int> *child1=new binaryTreeNode<int>(leftnode);
            front->left=child1;
            pandingnode.push(child1);
        }
        cout<<"enter the right node of"<<front->data<<endl;
        int rightnode;
        cin>>rightnode;
        if(rightnode!=-1)
        {
            binaryTreeNode<int> *child2=new binaryTreeNode<int>(rightnode);
            front->right=child2;
            pandingnode.push(child2);
        }
    }
    return root;
}
//count nodes
int NodeNum(binaryTreeNode<int>*root)
{
    if(root==NULL)
    {
      return 0;
    }
    return 1+NodeNum(root->left)+NodeNum(root->right);
}
int height(binaryTreeNode<int>*root){
if(root==0)
{
    return 0;
}
int l=height(root->left);
int r=height(root->right);
    return 1+ max(l,r);

}
int main()
{
    binaryTreeNode<int> *root=takeInputLevelWise();
    print(root);
    int ans=NodeNum(root);
    cout<<ans;
    int h =height(root);
    cout<<"Tree height:"<<h;
}

