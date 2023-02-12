#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],int i,int n,vector<int> &v,int sum)
{
    if(i==n)
    {
        // for(auto it : v)
        // {
        //     cout << it << " ";
        // }
        // cout << endl;
        v.push_back(sum);
        return;
    }
    // v.push_back(arr[i]);
    sum += arr[i];
    solve(arr, i + 1, n, v,sum);
    // v.pop_back();
    sum -= arr[i];
    solve(arr, i + 1, n, v,sum);
}
int main()
{
    int arr[] = {3, 1, 2};
    int sum = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> v;
    solve(arr, 0, size, v,sum);
    sort(v.begin(), v.end());
    for(auto it :v)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}