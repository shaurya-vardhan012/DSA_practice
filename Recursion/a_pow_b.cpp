#include<bits/stdc++.h>
using namespace std;
int solve(int a,int b) // T(N) = O(b)
{
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a;
    }
    return a * solve(a, b - 1);
}
int solve2(int a,int b)// T(N)=O(log(b))
{
    if(b==1)
    {
        return a;
    }
    int temp = solve2(a, b / 2);
    if(b%2==0)
    {
        return temp * temp;
    }
    else
    {
        return a * temp * temp;
    }
}
int main()
{
    int s;
    s = solve2(3,3);
    cout << s << endl;
    return 0;
}