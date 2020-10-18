#include<iostream>
#include<cstdlib>
#include"BinarySearchNode.cpp"
using namespace std;
BinarySearchNode <int> * insertBinary(BinarySearchNode<int>*root,int key)
{
    if(root==0)
    {
        BinarySearchNode<int> *root=new BinarySearchNode<int>(key);
         root->left=0;
        root->right=0;
    }
    else if(root->data>key)
    {
        root->left=insertBinary(root->left,key);
    }
    else if(root->data<key)
    {
        root->right=insertBinary(root->right,key);
    }
    else{
        cout<<"bhai km se km duplicate key mt dal chuna lgayega kya";
    }
    return root;
}
BinarySearchNode<int>* SearchBinary(BinarySearchNode<int>*root,int key)
{
    if(root==0)
    {
        cout<<key<<" key not found";
        return 0;
    }
    if(key<root->data)
    {
        return SearchBinary(root->left,key);
    }
    else if(key>root->data)
    {
        return SearchBinary(root->right,key);
    }
    else
    {
        return root;
    }
}
// deletion in binary search tree
BinarySearchNode<int>* DeleteNode(BinarySearchNode<int>* root,int key)
{
    BinarySearchNode<int>* ptr,*par;
    ptr=root;
    par=0;
    while(ptr!=0)
    {
        if(ptr->data==key)
            break;
        par=ptr;
    }
    // not found
    if(ptr==0)
    {
        cout<<"data not found";
    }
    // if have 2 child
    else if(ptr->right!=0 && ptr->left!=0)
    {
       root = case_c(root,par,ptr);
    }
    // have right child
    else if(ptr->right!=0 && ptr->left==0)
    {
       root= case_b(root,par,ptr);
    }
    // have left child
    else if(ptr->left!=0 && ptr->right==0)
    {
        root= case_b(root,par,ptr);
    }
    // leaf node
    else if(ptr->left==0 && ptr->right==0)
    {
        root= case_a(root,par,ptr);
    }
    return root;
}
BinarySearchNode<int>* case_a(BinarySearchNode<int>* root,BinarySearchNode<int>* par,BinarySearchNode<int>*ptr)
{
    // root node delete
    if(par==0)
    {
        root=0;
    }
    //check  delete node??
    if(par->left==ptr)
    {
        par-left=0;
    }
    else
    {
        par->right=0;
    }
    //delete node
    delete ptr;
    //return node
    return root;
}
BinarySearchNode<int>* case_b(BinarySearchNode<int>* root,BinarySearchNode<int>* par,BinarySearchNode<int>*ptr)
{
    //create one another pointer
    BinarySearchNode<int>*child;
    // root node delete
    if(par==0)
    {
        root=0;
    }
    // check ptr's child
    if(ptr->left!=0)
    {
        child=ptr->left;
    }
    else
    {
        child=ptr->right;
    }
    //check node ??
    if(par->left==ptr)
    {
        par->left=child;
    }
    else{
        par->right=child;
    }
    delete ptr;
    return root;
}
BinarySearchNode<int>* case_b(BinarySearchNode<int>* root,BinarySearchNode<int>* par,BinarySearchNode<int>*ptr)
{
    BinarySearchNode<int>* parsuc=ptr;
    BinarySearchNode<int>* suc=ptr->right;
    while(suc->left!=0)
    {
        parsuc=ptr;
        suc=suc->left;
    }
    ptr->data= suc->data;
    if(ptr->right!=0)
    {
       root= case_b(root,parsuc,suc);
    }
    else
    {
        root= case_a(root,parsuc,suc);
    }
    return root;
}
// end delete code

// print tree


//         9 6 7 15 5 3 11 18
int main()
{
    BinarySearchNode<int> *root=NULL;
    int choice,key;
    while(1)
    {
        cout<<"1.insert element"<<endl;
        cout<<"9.exit"<<endl;
        cin>>choice;
        switch(choice){
    case 1:
        cout<<"enter the inserted key";
        cin>>key;
        root=insertBinary(root,key);
        break;
    case 2:
        cout<<"enter search key";
        cin>>key;
        BinarySearchNode(root,key);

    case 9:
        exit(-1);
        }

    }
}
