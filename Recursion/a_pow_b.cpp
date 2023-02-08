#include<bits/stdc++.h>
using namespace std;
int solve(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    return a * solve(a, b - 1);
}
int main()
{
    int s;
    s = solve(3,1);
    cout << s << endl;
    return 0;
}