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

int max_depth(node* root)
{
    if(root == NULL )
        return 0;

    int l = max_depth(root->left);
    int r = max_depth(root->right);
    return 1 + max(l, r);
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
    root->right->left->left = new node(8);
    cout << "The maximum height of the tree is : " << max_depth(root);
    return 0;
}