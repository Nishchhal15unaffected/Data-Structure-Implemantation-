#include<iostream>
#include "treenode.h"
#include<queue>
using namespace std;
//printing tree by pr.order and by recursion
void print(treenode<int> *root)
{
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<":";
    for(int i=0;i<root->childern.size();i++)
    {
        cout<<root->childern[i]->data<<" ";
    }
    cout<<endl;

    for(int i=0;i<root->childern.size();i++)
    {
        print(root->childern[i]);
    }

}
// take input by recursion
treenode<int>* takeInput()
{
    int root_data;
    cout<<"enter data";
    cin>>root_data;
    treenode<int> *root=new treenode<int>(root_data);
    cout<<"enter no of childern of "<<root->data<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        treenode<int> *child=takeInput();
        root->childern.push_back(child);
    }
    return root;
}
//take input by queue or no recursion
treenode<int>* takeInputlevelwise()
{
    int root_data;
    cout<<"enter the data";
    cin>>root_data;
    treenode <int> *root= new treenode<int>(root_data);
    queue<treenode<int>*> pandingnode;
    pandingnode.push(root);
    while(pandingnode.size()!=0)
r    {
        treenode<int> *front = pandingnode.front();
        pandingnode.pop();
    cout<<"enter the number of children of "<<front->data<<endl;
    int child_num;
    cin>>child_num;
    for(int i=0;i<child_num;i++)
    {
        int child_data;
        cout<<"enter"<<i<<"th child of"<<front->data<<endl;
        cin>>child_data;
        treenode<int> *child=new treenode<int>(child_data);
        front->childern.push_back(child);
        pandingnode.push(child);
    }
}
    return root;
}
int count(treenode<int> *root)
{
    int ans=1;

    for(int i=0;i<root->childern.size();i++)
    {
        ans += count(root->childern[i]);
    }
    return ans;
}
void printAtKlevel(treenode<int> *root,int k)
{
    if(k==0)
    {
        cout<<"kth element: "<<root->data<<endl;
    }
    for(int i=0;i<root->childern.size();i++)
    {
        printAtKlevel(root->childern[i],k-1);
    }
}
// delete function
void deleteNode(treenode<int>*root)
{
    for(int i=0;i<root->childern.size();i++)
    {
        deleteNode(root->childern[i]);
    }
    delete root;
}

int main()
{

   /* manual created nodes
   int rootdata;
    cout<<"enter the root data";
    cin>>rootdata;
   treenode<int>*root=new treenode<int>(rootdata);
   treenode<int>*node1=new treenode<int>(19);
    treenode<int>*node2=new treenode<int>(20);
    root->childern.push_back(node1);
    root->childern.push_back(node2);*/
  //  treenode<int> *root=takeInput();
    treenode<int>*root=takeInputlevelwise();
    print(root);
    int ans=count(root);
    cout<<ans<<endl;
    cout<<"enter the k and find the kth element data"<<endl;
    int k;
    cin>>k;
    printAtKlevel(root,k);
}
