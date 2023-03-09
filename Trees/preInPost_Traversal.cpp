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

void preInPost(node * root)
{
    if(root==NULL)
        return;

    vector<int> pre, in, post;
    stack<pair<node *, int>> st;
    st.push({root, 1});
    while(!st.empty())
    {
        auto it = st.top();
        st.pop();

        if(it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            
            if(it.first->left!=NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        else if(it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right!=NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            post.push_back(it.first->data);
        }
    }
    for(auto it:pre)
    {
        cout << it << " ";
    }
    cout << endl;
    for(auto it:in)
    {
        cout << it << " ";
    }
    cout << endl;
    for(auto it:post)
    {
        cout << it << " ";
    }
    cout << endl;
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
    preInPost(root);
    return 0;
}