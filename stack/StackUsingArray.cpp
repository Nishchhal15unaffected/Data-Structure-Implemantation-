#include<iostream>
using namespace std;
template <class t>
class stackA
{
    t *data;
    int index;
    int capacity;
public:

    stackA()
    {
        data=new t[5];
        index=0;
        capacity=5;
    }
    void push(t element )
    {
        if(index==capacity)
        {
            t *newArray=new t[2*capacity];
            for(int i=0;i<index;i++)
            {
                  newArray[i] =data[i];
            }
            delete data;
            data=newArray;
            capacity=2*capacity;
        }
        data[index]=element;
        index++;
    }
    bool isEmpty()
    {
        return index==0;
    }
    t pop()
    {
       if(isEmpty())
       {
           cout<<"stack is empty";
           return 0 ;
       }
       index--;
       return data[index];
    }
    int size()
    {
        return index;
    }
    t top()
    {
        return data[index-1];
    }

};


int main()
{
stackA <float>s;
s.push(3.5);
cout<<s.top();
}
