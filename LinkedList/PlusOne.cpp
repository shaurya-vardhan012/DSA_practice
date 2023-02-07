#include<bits/stdc++.h>
using namespace std;

class node 
{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void insert(node* &head,int val)
{
    node* n=new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp=head;
    while(head->next!=NULL)
    {
        head=head->next;
    }
    head->next=n;
    head=temp;
}
void reverse(node* &head)
{
    if(head==NULL)
    {
        return;
    }
    node* curr=head;
    node* prev=NULL;
    node* next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}

void plusOne(node* &head)
{
    node* temp=head;
    int carry=0;
    while(temp!=NULL)
    {
        if(temp->data+1>9)
        {
            temp->data=0;
            carry=1;
            if(temp->next==NULL)
            {
                insert(head,1);
                break;
            }
        }
        else
        {
            temp->data=temp->data+1;
        }
        temp=temp->next;
    }
    reverse(head);
}

int main()
{
    node* head=NULL;
    insert(head,4);
    insert(head,5);
    insert(head,6);
    // insert(head,4);
    // insert(head,9);
    print(head);
    reverse(head);
    print(head);
    plusOne(head);
    print(head);
}