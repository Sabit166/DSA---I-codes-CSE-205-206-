#include <bits/stdc++.h>
using namespace std;
#define base 256
#define mod 1000000007

class Hash
{
    string str;
    int sz;
    vector<long long> prehash;
    vector<long long> power;

    void PrefixHash()
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
    Hash() {}
    Hash(string &s)
    {
        str = s;
        sz = s.size();
        prehash.resize(sz);
        power.resize(sz + 1);
        PrefixHash();
    }

    long long CalHash(int L, int R)
    {
        if (L == 0) return prehash[R];
        return (prehash[R] - ((prehash[L - 1] * power[R - L + 1]) % mod) + mod) % mod;
    }
};

vector<string> common_phrase(string &s1, string &s2, int n)
{
    int a = s1.size();
    int b = s2.size();
    
    if (n > a || n > b) return {};

    set<string> phrases;

    Hash hash1(s1);
    Hash hash2(s2);

    for (int i = 0; i <= a - n; i++)
    {
        for (int j = 0; j <= b - n; j++)
        {
            long long h1 = hash1.CalHash(i, i + n - 1);
            long long h2 = hash2.CalHash(j, j + n - 1);

            //cout << i << ' ' << j << ' '<< h1 << ' ' <<h2 << endl;
            if (h1 == h2)
            {
                phrases.insert(s1.substr(i, n));
            }
        }
    }
    return vector<string>(phrases.begin(), phrases.end());
}

string remove_space(string s)
{
    string str;
    for (auto &it : s)
        if (it != ' ')
            str += it;
    return str;
}

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    str1 = remove_space(str1);
    str2 = remove_space(str2);

    int length;
    cin >> length;

    if (length <= 0)
    {
        cout << -1;
        return 0;
    }

    vector<string> phrases = common_phrase(str1, str2, length);

    if (phrases.empty())
        cout << -1;
    else
    {
        for (auto &it : phrases)
            cout << it << endl;
    }

    return 0;
}
