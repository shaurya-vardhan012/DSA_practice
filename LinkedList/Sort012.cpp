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


// Brute Force 
void sort012(Node* &head)
{
    int arr[3]={0};
    Node* temp=head;
    while(temp!=NULL)
    {
        arr[temp->data]++;
        temp=temp->next;
    }
    Node* newNode=head;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<arr[i];j++)
        {
            newNode->data=i;
            newNode=newNode->next;
        }
    }
}


//

int main()
{
    Node* head=NULL;
    insert(head,1);
    insert(head,1);
    insert(head,2);
    insert(head,0);
    insert(head,0);
    insert(head,1);
    insert(head,2);
    sort012(head);
    print(head);
    return 0;
}