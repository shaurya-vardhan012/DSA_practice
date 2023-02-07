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
    map<int,bool> visited;
    visited[temp->data]=1;
    Node* prev=temp;
    temp=temp->next;
    while(temp!=NULL)
    {
        if(visited[temp->data])
        {
            prev->next=temp->next;
            free(temp);
        }
        else
        {
            visited[temp->data]=1;
            prev=temp;
        }
        temp=prev->next;
    }
}

int main()
{
    Node* head=NULL;
    insert(head,2);
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,1);
    insert(head,4);
    insert(head,5);
    removeDuplicate(head);
    print(head);
    return 0;
}