#include<bits/stdc++.h>
using namespace std;
void solve(int a[],vector<int> &v,int i,int n)
{
    if(i==n)
    {
        cout << "[";
        for(auto it :v)
        {
            cout << it << " ";
        }
        cout <<"]"<< endl;
        return;
    }
    v.push_back(a[i]);
    solve(a, v, i + 1, n);
    v.pop_back();
    solve(a, v, i + 1, n);
}
int main()
{
    int a[] = {3,2,1};
    vector<int> v;
    int size = sizeof(a) / sizeof(a[0]);
    solve(a, v, 0, size);

    return 0;
}