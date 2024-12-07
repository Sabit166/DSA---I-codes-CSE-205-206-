#include <bits/stdc++.h>
using namespace std;
#define base 256
#define mod 1000000007

class Hash
{
    string str;
    vector<long long> prehash;
    vector<long long> power;
    int sz;

    void prefixhash()
    {
        long long x = 0;
        power[0] = 1;
        for (int i = 0; i < sz; i++)
        {
            power[i + 1] = (power[i] * base) % mod;
            x = ((x * base) % mod + str[i]) % mod;
            prehash[i] = x;
        }
    }

public:
    Hash(string &s)
    {
        str = s;
        sz = s.size();
        prehash.resize(sz);
        power.resize(sz + 1);
        prefixhash();
    }

    long long calhash(int L, int R)
    {
        if (L == 0)
            return prehash[R];
        return (prehash[R] - (prehash[L - 1] * power[R - L + 1]) % mod + mod) % mod;
    }
};

string occurance(string &s1, string &s2, int n)
{
    int a = s1.size();
    int b = s2.size();
    int cnt;
    string substr;
    string maxprefix = "IMPOSSIBLE";

    Hash hash1(s1);
    Hash hash2(s2);
    
    for(int i = 1; i <= b ; i++)
    {
        cnt = 0;
        for(int j = 0 ; j <= a - i ; j++)
        {
            if(hash1.calhash(j, j + i - 1) == hash2.calhash(0 , i - 1)) cnt++;
        }
        if(cnt >= n) maxprefix = s2.substr(0,i);
    }
    return maxprefix;
}

int main()
{
    int t, a;
    string s1, s2;

    getline(cin, s1);
    getline(cin, s2);
    cin >> a;

    cout << occurance(s1, s2, a);
}