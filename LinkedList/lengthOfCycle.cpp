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

void lengthOfCycle(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        cout<<"\nThe list is not circular in nature\n";
        return;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            break;
        }
    }
    int cnt=1;
    Node *temp =slow;
    while(slow!=NULL)
    {
        slow=slow->next;
        cnt++;
        if(slow==temp) break;
    }
    cout<<"The length of the Cycle of list is "<<cnt<<endl;
}

int main()
{
    Node* head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    lengthOfCycle(head);
    head->next->next->next->next->next = head->next;
    return 0;
}