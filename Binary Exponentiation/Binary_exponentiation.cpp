#include <bits/stdc++.h>
using namespace std;

int power(int a, int n)
{
    if(n==0) return 1;
    if(n>0 && n%2==0)
    {
        //even
        int x=power(a,n/2);
        return x*x; 
    }
    if(n>0 && n%2==1)
    {
        //odd
        int x=power(a,(n-1)/2);
        return x*x*a;
    }
}

int main()
{
    int a, n;
    cin >> a >> n;

    cout << power(a, n) << endl; /// 2^4=16
}