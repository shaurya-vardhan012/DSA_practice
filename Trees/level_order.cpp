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

void level_order(node* root)
{
    vector<vector<int>> result;
    if(root== NULL) 
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size;i++)
        {
            node* n = q.front();
            q.pop();
            if(n->left!=NULL)
            {
                q.push(n->left);
            }
            if(n->right!=NULL)
            {
                q.push(n->right);
            }
            level.push_back(n->data);
        }
        result.push_back(level);
    }
    for(auto i:result)
    {
        for(auto it:i)
        {
            cout << it << " ";
        }
        cout << endl;
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
    level_order(root);
    return 0;
}