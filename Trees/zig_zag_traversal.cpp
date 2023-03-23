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

void zig_zag_traversal(node* root)
{
    vector<vector<int>> result;
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty())
    {
        int size = q.size();
        vector<int> row(size);
        for (int i = 0; i < size;i++)
        {
            node *n = q.front();
            q.pop();
            int index = leftToRight ? i : (size - i - 1);

            row[index] = n->data;
            if(n->left)
            {
                q.push(n->left);
            }
            if(n->right)
            {
                q.push(n->right);
            }
        }
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    for(auto it : result)
    {
        for(auto i:it)
        {
            cout << i << " ";
        }
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
    zig_zag_traversal(root);
    return 0;
}