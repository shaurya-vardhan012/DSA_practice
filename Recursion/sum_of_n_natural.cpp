#include<bits/stdc++.h>
using namespace std;
void solve(int n,int &sum)
{
    if(n==0)
    {
        return;
    }
    sum += n;
    solve(n - 1, sum);
}
int solve2(int n)
{
    if(n==1)
        return 1;

    return n + solve2(n - 1);
}

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    solve(n,sum);
    cout << solve2(n) << endl;
    return 0;
}