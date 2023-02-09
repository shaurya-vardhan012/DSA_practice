#include<bits/stdc++.h>
using namespace std;
bool solve(int arr[],int l,int r)
{
    if(l>=r)
        return true;
    if(arr[l]!=arr[r])
        return false;
    solve(arr, l + 1, r - 1);
}


int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++)
    {
        cin >> arr[i];
    }
    cout<<solve(arr, 0, n - 1);
    return 0;
}