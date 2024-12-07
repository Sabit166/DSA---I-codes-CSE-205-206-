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
    Hash(string& s)
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

int occurance(string &s1, string &s2)
{
    int a = s1.size();
    int b = s2.size();
    int c = min(a,b);

    Hash hash1(s1);
    Hash hash2(s2);

    for (int i = 0; i < c; i++)
    {
        if(hash1.calhash(0,i) != hash2.calhash(0,i)) return i;
    }
    return c;
}

int main()
{
    int t, a;
    string s;

    cin >> s >> t;

    while(t--)
    {
        cin >> a;

        string s1 = s.substr(0,a);
        string s2 = s.substr(a, s.size() - a);

        cout << occurance(s1, s2) << "\n";
    }
}