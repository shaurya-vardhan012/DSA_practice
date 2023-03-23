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

void bottom_view(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
       return;
    }
    map<int, int> mp;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        node *n = p.first;
        int line = p.second;
        mp[line] = n->data;
        if (n->left != NULL)
            q.push({n->left, line - 1});
        if (n->right != NULL)
            q.push({n->right, line + 1});
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    for (auto it : ans)
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
    bottom_view(root);
    return 0;
}