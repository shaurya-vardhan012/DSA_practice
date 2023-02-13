#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],int i,int n,vector<int> &ds,vector<vector<int>> &ans)
{
    ans.push_back(ds);
    for (int j = i;j < n;j++)
    {
        if(j!=i && (arr[j] ==arr[j-1])) continue;
        ds.push_back(arr[j]);
        solve(arr, j + 1, n, ds, ans);
        ds.pop_back();
    }
}
int main()
{
    int arr[] = {3,1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> v;
    vector<vector<int>> ans;
    sort(arr, arr + size);
    solve(arr, 0, size, v, ans);
    for(auto f:ans)
    {
        cout << "[ ";
        for(auto it:f)
        {
            cout << it << " ";
        }
        cout<<"]" << endl;
    }
    return 0;
}