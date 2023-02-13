#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],int n,vector<int> &ds,vector<vector<int>> &ans,int freq[])
{
    if(ds.size()==n){
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < n;i++)
    {
        if(!freq[i])
        {
            freq[i] = 1;
            ds.push_back(arr[i]);
            solve(arr, n, ds, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}
int main()
{
    int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> ds;
    vector<vector<int>> ans;
    int freq[size] = {0};
    for (int i = 0; i < size;i++)
        freq[i] = 0;

    solve(arr,size, ds, ans, freq);
    for (auto f : ans)
    {
        cout << "[ ";
        for (auto it : f)
        {
            cout << it << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}