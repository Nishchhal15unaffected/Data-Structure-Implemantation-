#include<iostream>
using namespace std;
template<typename t>
class BinarySearchNode{
    public:
        t data;
BinarySearchNode<t>* left;
BinarySearchNode<t>* right;
BinarySearchNode(t data)
{
    this->data=data;
    left=0;
    right=0;
}

};
