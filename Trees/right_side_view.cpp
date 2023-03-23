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

void right_view(node* root)
{
    vector<int> ans;
    // vector<vector<int>> res;
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size;i++)
        {
            node *n = q.front();
            q.pop();
            if(n->left!=NULL)
            {
                q.push(n->left);
            }
            if(n->right)
            {
                q.push(n->right);
            }
            level.push_back(n->data);
        }
        reverse(level.begin(), level.end());
        // res.push_back(level);
        ans.push_back(level[0]);
    }
    for(auto it : ans)
    {
        cout << it << " ";
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
    right_view(root);
    return 0;
}