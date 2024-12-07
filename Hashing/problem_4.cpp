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

int occurance(string &s, int a, int b)
{
    set<long long>occurances;
    
    Hash hash(s);

    for (int i = 0; i <= a - b; i++)
    {
        occurances.insert(hash.calhash(i, i + b - 1));
    }
    return occurances.size();
}

int main()
{
    int t,a,b;
    string s;

    cin >> t;

    while(t--)
    {
        cin >> a >> b >> s;
        cout << occurance(s, a, b) << "\n";
    }
}