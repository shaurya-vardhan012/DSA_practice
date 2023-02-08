#include<bits/stdc++.h>
using namespace std;
void solve(int n) // with loop
{
    if(n==1)
    {
        cout << "* ";
        return;
    }
    for (int i = 0; i < n;i++)
    {
        cout << "* ";
    }
    cout << endl;
    solve(n - 1);
}

void solve1(int n,int i)// without loop
{
    if(n==0)
    {
        return;
    }
    if(i<n)
    {
        cout << "* ";
        solve1(n, i + 1);
    }
    else
    {
        cout << endl;
        solve1(n - 1, 0);
    }
}

int main()
{
    solve1(5,0);
    return 0;
}