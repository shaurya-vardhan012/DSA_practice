#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
        int data;
        node *right;
        node *left;
        node(int val)
        {
            data = val;
            right = left = NULL;
        }
};

void inorder(node * root)
{
    if(root==NULL)
    {
            return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node * root)
{
    if(root==NULL)
    {
            return;
    }
    cout << root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node * root)
{
    if(root==NULL)
    {
            return;
    }
    preorder(root->left);
    preorder(root->right);
    cout << root->data<<" ";
}

int main()
{
    node *root = new node(0);
    root->left = new node(1);
    root->left->left = new node(2);
    root->left->right = new node(3);
    root->right = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);
    inorder(root);
    cout << "\n";
    preorder(root);
    cout << "\n";
    postorder(root);
    return 0;
}