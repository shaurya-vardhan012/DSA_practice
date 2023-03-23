#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node *left;
        node *right;
        node(int val)
        {
            data = val;
            left = right = NULL;
        }
};
bool isLeaf(node *root)
{
        return !root->left && !root->right;
}

void addLeft(node* root,vector<int> &res)
{
    node * curr=root->left;
    while(curr)
    {
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->left) curr=curr->left;
        else curr=curr->right;
    }
}


void addRight(node* root,vector<int> &res)
{
    node *curr = root->right;
    vector<int> temp;
    while(curr)
    {
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->right) curr=curr->right;
        else curr=curr->left;
    }
    for (int i = temp.size()-1; i >= 0;i--)
    {
        res.push_back(temp[i]);
    }
}

void addLeaf(node* root,vector<int> &res)
{
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left) addLeaf(root->left,res);
    if(root->right) addLeaf(root->right,res);
}



void printBoundary(node* root)
{
    vector<int> res;
    if(!root) return;
    if(!isLeaf(root)) res.push_back(root->data);
    addLeft(root, res);
    addLeaf(root, res);
    addRight(root, res);
    for(auto it : res)
    {
        cout<<it<<" ";
    }
}

int main()
{
    node *root = new node(0);
    root->left = new node(1);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->right = new node(5);
    root->right->left = new node(6);
    printBoundary(root);
    return 0;
}