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


bool isCircular(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return false;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return true;
        }
    }
    return false;
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
    if(isCircular(head))
    {
        cout<<"\nYes,the list is not circular\n";
    }
    else{
        cout<<"\nNo, the list is not circular\n";
    }
    return 0;

}