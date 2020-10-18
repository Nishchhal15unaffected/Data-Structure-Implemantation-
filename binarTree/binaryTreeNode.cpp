#include<iostream>
using namespace std;
template <typename t>
class binaryTreeNode
{
public:
    t data;
    binaryTreeNode<t>*left;
    binaryTreeNode<t>*right;
    binaryTreeNode(t data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
