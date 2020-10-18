#include<iostream>
using namespace std;
template <typename t>
class node{
public:
    node <t>* prev;
    t data;
    node<t> *next;
public:
    node(t data)
    {
        prev=NULL;
        this->data=data;
        next=NULL;
    }
};
