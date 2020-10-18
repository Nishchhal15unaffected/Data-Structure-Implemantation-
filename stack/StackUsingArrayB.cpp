#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 10
int stack_arr[MAX];
int top=-1;
void push( int item);
int pop();
int peek();
int isEmpty();
int isFull();
void display();
int main()
{
    int choice,item;
    while(1)
    {
        cout<<"1.Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3.Display the top element"<<endl;
        cout<<"4. Display all stack element"<<endl;
        cout<<"5.Quite"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
                cout<<"Enter the item to be pushed : ";
                cin>>item;
                push(item);
                break;
        case 2:
                item=pop();
                cout<<"Popped item is : ",item;
                break;
        case 3:
                cout<<"Item at the top is : ",peek();
                break;
        case 4:
                display();
                break;
        case 5:
                exit(1);
        default :
                cout<<"Wrong choice "<<endl;
        }
        //end switch
    }
    //end while loop
}
    void push(int item)
    {
        if(isFull())
        {
            cout<<"Stack overflow ";
            return 0;
        }
        top=top+1;
        stack_arr[top]=item;
    }
    int pop()
    {
        if(isEmpty()){
            cout<<"stack underflow";
            return 0;
        }
        int item=stack_arr[top];
        top=top-1;
        return item;
    }
    int peek()
    {
        if(isEmpty())
        {
            cout<<"stack underflow";
            return 0;
        }
        return stack_arr[top];
    }
    int isEmpty()
    {
        if(top==-1)
            return 1;
        else
            return 0;
    }
    int isFull()
    {
        if(MAX-1==top)
            return 1;
        else
            return 0;
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"stack underflow"<<endl;
            return;
        }
        cout<<"elements is"<<endl;
        for(int i=top;i>=0;i--)
        {
            cout<<stack_arr[i]<<endl;
        }
    }
