#include<iostream>
#include<stdlib.h>
#include "DLLNode.cpp"
using namespace std;
//template<typename t>
node<int>* takeinput()
{
    node<int> *head=NULL;
    cout<<"enter data";
    int data;
    cin>>data;
    node<int> *tail;
    while(data!=-1)
    {
        node <int>*newnode=new node<int>(data);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            newnode->prev=tail;
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node<int>*head)
{
    while(head!=NULL)
    {
        cout<<head->data;
        head=head->next;
    }
}
node<int>* addAtEmpty(node<int> *head)
{
    int data;
    cout<<"enter the data";
    cin>>data;
    node<int>*temp=new node<int>(data);
    head=temp;
    return head;
}
node<int>* addAfterNode(node<int> *head ,int item)
{
    int data;
    cout<<"enter the data";
    cin>>data;
    node<int> *newnode=new node<int>(data);
    node<int>* temp=head;
    while(temp!=NULL)
    {   if(temp->data==item){
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
        return head;
    }
    temp=temp->next;
    }
     cout<<"element not found ";
     return head;
}
node<int>* addBeforeNode(node<int>* head, int data,int item)
{
    node<int>* newnode=new node<int>(data);
    node <int> * temp=head;
    while(temp!=NULL)
    {
        if(temp->next->data==item)
        {
          newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
        return head;
        }
        temp=temp->next;
    }
    return head;
}
node<int>* deleteNode(node<int>* head,int item)
{
    node<int>*temp=head;
    while(temp!=NULL)
    {
        if(temp->next->data==item)
        {
            node<int> *a=temp->next;
            node<int> *b=a->next;
            temp->next=a->next;
            b->prev=a->prev;
            delete a;
            return head;
        }
        temp=temp->next;
    }
        cout<<"element not found";
        return head;
}
node<int>* reverseNode(node<int>* head)
{
    node<int>* p1;
    node<int>*p2;
    p1=head;
    p2=p1->next;
    p1->next=NULL;
    p1->prev=p2;
    while(p2!=NULL)
    {
        p2->prev=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p2->next;
    }
    head=p1;
    return head;
}
int main()
{
    int ch,item,data;
    node<int> *head=NULL;
    while(1)
    {
    cout<<"1.teke input"<<endl;
    cout<<"2.node insert at empty list"<<endl;
    cout<<"3.After node insert"<<endl;
    cout<<"4.Before node insert"<<endl;
    cout<<"5.delete node"<<endl;
    cout<<"6.print"<<endl;
    cout<<"7.exit"<<endl;
    cout<<"8.reverse"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
            head=takeinput();
            break;
    case 6:
            print(head);
            break;
    case 2:
            head=addAtEmpty(head);
            break;
    case 3:
            cout<<"enter the data after inserted";
            cin>>item;
            head=addAfterNode(head ,item);
            break;
    case 4:
            cout<<"enter the data to be inserted";
            cin>>data;
            cout<<"enter the data before inserted";
            cin>>item;
            head=addBeforeNode(head, data,item);
            break;
    case 5:
            cout<<"enter the data to be delete";
            cin>>item;
            head=deleteNode(head,item);
            break;
    case 8:
            head=reverseNode(head);
            break;
    case 7:
            exit(1);
            break;

    default:
            cout<<"sale chutiya bc sai number dal andhe dikta ni kya upr";
    }

}
}
