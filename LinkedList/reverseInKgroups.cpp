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

void print(Node* head)
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

Node* KReverse(Node* &head,int k)
{
    if(head==NULL)
    {
        return NULL;
    }

    Node* next=NULL;
    Node* curr=head;
    Node* prev=NULL;
    int cnt=0;
    while(curr!=NULL && cnt<k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        cnt++;
    }
    if(next!=NULL)
    {
        head->next=KReverse(next,k);
    }
    return prev;
}

int main()
{
    Node* head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    head=KReverse(head,3);
    print(head);
    return 0;
} 