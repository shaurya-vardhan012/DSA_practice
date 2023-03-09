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

int height(node* root,int &maxi)
{
    if(root == NULL)
        return 0;
    int l = height(root->left, maxi);
    int r = height(root->right, maxi);
    maxi = max(maxi, l + r);
    return 1 + max(l , r);
}

int daimeter(node * root)
{
    int maxi = 0;
    height(root, maxi);
    return maxi;
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
    cout << "Diameter : " << daimeter(root);
    return 0;
}