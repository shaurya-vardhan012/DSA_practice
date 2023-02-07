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

void removeDuplicate(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        if((temp->next!=NULL) &&temp->data==temp->next->data)
        {
            Node* next_next=temp->next->next;
            Node* toDelete=temp->next;
            delete(toDelete);
            temp->next=next_next;
        }
        else
        {
            temp=temp->next;
        }
    }
}

int main()
{
    Node* head=NULL;
    insert(head,1);
    insert(head,1);
    insert(head,2);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    removeDuplicate(head);
    print(head);
    return 0;
}