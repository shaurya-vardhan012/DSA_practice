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


void preorder(node * root)
{
    vector<int> preorder;
    if(root == NULL)
    {
        return;
    }
    stack<node *> st;
    st.push(root);
    while(!st.empty())
    {
        root = st.top();
        st.pop();
        preorder.push_back(root->data);
        if(root->right!=NULL)
            st.push(root->right);
        if(root->left!=NULL)
            st.push(root->left);
    }
    for(auto it : preorder)
    {
        cout << it << " ";
    }
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
    preorder(root);
    return 0;
}   