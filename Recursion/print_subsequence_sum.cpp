#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],vector<int> &v,int i ,int n, int sum,int target,bool &flag)
{
    if(i==n)
    {
        if(sum==target && flag==false)
        {
            for(auto it : v)
            {
                cout << it << " ";
            }
            cout << endl;
            flag = true;
        }
        return;
    }
    v.push_back(arr[i]);
    sum += arr[i];
    solve(arr, v, i + 1, n, sum , target,flag);
    v.pop_back();
    sum -= arr[i];
    solve(arr, v, i + 1, n, sum , target,flag);
}
int main()
{
    int arr[] = {1, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    // cout << size;
    int sum =0 ;
    int target;
    cout << "Enter the target value : ";
    cin >> target;
    vector<int> v;
    bool flag = false;
    solve(arr, v, 0, size, sum, target,flag);
    return 0;
}