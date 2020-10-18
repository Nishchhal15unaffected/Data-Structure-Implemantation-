#include<iostream>
#include<vector>
using namespace std;
template<typename t>
class treenode
{
    public:
    t data;
    vector <treenode<t> *>childern;
    treenode(t data)
    {
        this->data=data;
    }
    ~treenode()
    {
        for(int i=0;i<root->childern.size();i++)
        {
            delete childern[i];
        }
    }
};
