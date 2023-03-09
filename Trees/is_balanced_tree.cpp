#include <bits/stdc++.h>
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

bool check(node* root)
{
    if(root == NULL)
    {
        return true;
    }
    int l = check(root->left);
    int r = check(root->right);
    if(abs(l - r)>1)
    {
        return false;
    }
    bool left = check(root->left);
    bool right = check(root->right);
    if(!left || !right)
    {
        return false;
    }
    return true;
}

int main()
{
    node *root = new node(0);
    root->left = new node(1);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(5);
    root->right->left = new node(6);
    // root->right->left->left = new node(6);
    root->right->left->right = new node(6);
    cout<<check(root);
    return 0;
}