#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

void print(Node * head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

void insert(Node* &head,int val)
{
    Node* n = new Node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    Node* temp=head;
    while(head->next!=NULL)
    {
        head=head->next;
    }
    head->next=n;
    head=temp;
}

void merge(Node* head1,Node* head2)
{
    if(head1==NULL)
    {
        return;
    }
    if(head2==NULL)
    {
        return;
    }
    Node* newNode=NULL;
    while(head1!=NULL && head2!=NULL && head1->next!=NULL && head2->next!=NULL)
    {
        if(head1->data<=head2->data)
        {
            insert(newNode,head1->data);
            head1=head1->next;
        }
        else
        {
            insert(newNode,head2->data);
            head2=head2->next;
        }
    }
    while(head1->next!=NULL)
    {
        insert(newNode,head1->data);
    }
    while(head2->next!=NULL)
    {
        insert(newNode,head2->data);
    }
    print(newNode);
}

int main()
{
    Node* head1=NULL;
    Node* head2=NULL;
    insert(head1,1);
    insert(head1,4);
    insert(head1,5);
    insert(head2,2);
    insert(head2,3);
    insert(head2,6);
    cout<<endl;
    print(head1);
    cout<<endl;
    print(head2);
    cout<<endl;
    merge(head1,head2);
    return 0;
}