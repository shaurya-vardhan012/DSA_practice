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

void reverse(Node* &head)
{
    if(head==NULL) return;
    Node* curr=head;
    Node *next=head->next;
    Node *prev=NULL;
    while(curr!=NULL)
    {
        curr->next=prev;
        prev=curr;
        curr=next;
        if(next!=NULL) next=next->next;
    }
    head=prev;
}

Node* reverseRec(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* newHead=reverseRec(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;

}

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

int main()
{
    Node* head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    print(head);
    // cout<<endl;
    // reverse(head);
    // print(head);
    cout<<endl;
    head=reverseRec(head);
    print(head);
    return 0;
}