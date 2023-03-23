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
int max_down(node* root,int &maxi)
{
    if(root==NULL)
    {
        return 0;
    }
    int l = max(0, max_down(root->left, maxi));
    int r = max(0, max_down(root->right, maxi));
    maxi = max(maxi, (l + r + root->data));
    return max(l, r) + root->data;
}

int maximum_path(node* root)
{
    int maxi = 0;
    max_down(root, maxi);
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
    cout << "The maximum path sum is : " << maximum_path(root);
    return 0;
}