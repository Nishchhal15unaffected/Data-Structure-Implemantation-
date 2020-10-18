#include<iostream>
using namespace std;
#include"Node.cpp"

 void print(Node *head)
    {
        Node * temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
    Node *TakeInput()
    {
        int data;
        cin>>data;
        Node *head =NULL;
        Node *tail=NULL;
        while(data!=-1)
        {
            Node *s=new Node(data);
            if(head==NULL)
            {
              head=s;
              tail=s;
            }
            else{
            tail->next=s;
            tail=tail->next;
            }
            cin>>data;
        }
        return head;
    }
    Node *insertNode(Node *head,int data,int index)
    {
        Node *s=new Node(data);
        Node *temp=head;
        int i=1;
        if(index==0)
        {
            s->next=head;
            head=s;
            return head;
            }
        while(temp!=0&&i<index-1)
        {
            temp=temp->next;
            i++;
        }
        if(temp!=NULL){
        s->next=temp->next;
        temp->next=s;
        }
        return head;
    }
    Node *DeleteNode(Node *head,int index)
    {
       int i=1;
       Node *temp=head;
       while(temp->next!=0&&i<index-1)
       {
            temp=temp->next;
           i++;
       }
       if(index==1)
       {
        Node *a=temp;
         Node *b=a->next;
            head=b;
            delete a;
            return head;
            }
       if(temp->next!=0)
       {
            Node *a=temp->next;
            Node *b=a->next;
            temp->next=b;
            delete a;
       }
        return head;
    }
Node* reverseNode(Node*head)
{
    Node *prev=NULL;
    Node *ptr=head;
    Node *n;
    while(ptr!=NULL)
    {
        n=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=n;
    }
    head=prev;
    return head;
}
Node* SelectionSort(Node* head)
{
    Node* p1;
    Node* p2;
    for(p1=head;p1->next!=NULL;p1=p1->next)
        for(p2=p1->next;p2!=NULL;p2=p2->next)
        {
            if(p1->data>p2->data)
            {
                   int temp=p1->data;
                   p1->data=p2->data;
                   p2->data=temp;
            }
        }
        return head;
}
Node* BubbleSort(Node* head)
{
    Node*p1;
    Node*p2;
    Node*end;
    for(end=NULL;end!=head->next;end=p2)
        for(p1=head;p1->next!=end;p1=p1->next)
    {   p2=p1->next;
        if(p1->data>p2->data)
        {
            int temp=p1->data;
            p1->data=p2->data;
            p2->data=temp;
        }
    }
    return head;
}
// sorting by exchanging the address
Node* SelectionSortA(Node* head)
{
    Node* p,*q,*r,*s;
    Node*temp;
    for(r=p=head;p->next!=NULL;r=p,p=p->next)
        for(s=q=p->next;q!=NULL;s=q,q=q->next)
    {
        if(p->data>q->data)
        {
            Node*a=p->next;
            Node*b=q->next;
            p->next=b;
            q->next=a;
            if(head!=p)
                r->next=q;
                s->next=p;
                if(head==p)
                head=q;
                temp=p;
                p=q;
                p=p;
        }
    }
    return head;
}
//sorting by exchanging the address
Node* BubbleSortA(Node*head)
{   Node* p=head;
    Node *q,*r;
    Node * end;
    for(end=NULL;end!=head->next;end=q)
        for(r=p=head;p->next!=end;r=p,p=p->next)
    {
        q=p->next;
        if(p->data>q->data)
        {
            p->next=q->next;
            q->next=p;
            if(head!=p)
                r->next=q;
            if(head==p)
                head=q;
            Node* temp=p;
            p=q;
            q=temp;
        }
    }
    return head;
}
Node* insertM(Node* head3,int data);
Node* insertM(Node* head3,int data)
{
    Node* temp=head3;
    Node* newnode=new Node(data);
    if(temp!=head3)
    {
    while(temp->next!=NULL)
    {

        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    }
    if(head3==NULL)
    {
        newnode->next=head3;
        head3=newnode;
        return head3;
    }
return head3;
}
//merging two list
void merging(Node*head1,Node*head2,Node*head3)
{
    Node* p1=head1;
    Node* p2=head2;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data>p2->data)
        {
            head3=insertM(head3,p2->data);
            p2=p2->next;
        }
        else if(p1->data<p2->data)
        {
            head3=insertM(head3,p1->data);
            p1=p1->next;
        }
        else if(p1->data==p2->data)
        {
            head3=insertM(head3,p1->data);
            p2=p2->next;
            p1=p1->next;
        }
    }
    while(p1!=NULL)
    {
        head3=insertM(head3,p1->data);
        p1=p1->next;
    }
    while(p2!=NULL)
    {
        head3=insertM(head3,p2->data);
        p2=p2->next;
    }
    print(head3);
}
//two linked list concatenation
Node* conc(Node*head1,Node*head2)
{
    Node* temp=head1;
    if(head1==NULL)
        head1=head2;
    if(head2==NULL)
        return head1;
    while(temp->next!=NULL)
        temp=temp->next;
        temp->next=head2;
        return head1;
}
void printNth(Node *head,int n)
{
    int i=1;
    Node *temp=head;
    while(i<n)
    {
        temp=temp->next;
        i++;
    }
    if(temp!=NULL)
    cout<<temp->data;
    else{
            cout<<"you enter wrong pos please enter right pos ";
    }
}
int main()
{
    //static type
/*    Node s1(10);
    Node *head=&s1;
    Node s2(20);
    s1.next=&s2;

    Node s3(30);
    s2.next=&s3;
    cout<<s1.data;*/
    //dynamic type
/*    Node *s4=new Node(40);
    Node *head=s4;
    Node *s5=new Node(50);
    s4->next=s5;
    Node *s6=new Node(60);
    s5->next=s6;
    s4->print(head);*/
    // right way to create node
   cout<<"enter the first list";
    Node * head1=TakeInput();
    cout<<"enter the nth pos, which you print";
    int n;
    cin>>n;
    printNth(head1,n);
    /*head1=BubbleSort(head1);
    cout<<"enter the second list";
    Node * head2=TakeInput();
    head2=BubbleSort(head2);
    head1=conc(head1,head2);
  //  Node * head3=NULL;*/
//merging(head1,head2,head3);
    //print(head3);
    //print(head1);
   /* int data,index;
    cout<<"insert Node position index and data"<<endl;
    cin>>index>>data;
    insertNode(head,data,index);
    print(head);
    int index2;
    cout<<"enter a delete no. node";
    cin>>index2;
    DeleteNode(head,index2);
    print(head);*/
   /* cout<<"reverse linked list";
    head=reverseNode(head);
    print(head);*/
    //head=BubbleSortA(head);
        //head=BubbleSort(head);
    //print(head);
}
