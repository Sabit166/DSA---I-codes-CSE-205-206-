#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define mod 151
#define base 256

class Hash
{
private:
    string str;
    int n;
    vector<int> pH;
    vector<int> power;

    void prefixHash()
    {
        int x = 0;
        int n = str.size();
        power[0] = 1;
        for (int i = 0; i < n; i++)
        {
            power[i + 1] = (power[i] * base) % mod;
            x = ((x * base) % mod + str[i]) % mod;
            pH[i] = x;
        }
    }

public:
    Hash() {};
    Hash(string &str1)
    {
        str = str1;
        n = str.size();
        pH.resize(n);
        power.resize(n + 1);
        prefixHash();
    }
    int calHash(int L, int R)
    {
        if (L == 0)    return pH[R];
        int x = ((pH[R] - (pH[L - 1] * power[R - L + 1]) % mod) + mod) % mod;
        return x;
    }
};

string LPS(string &s)
{
    int n = s.size();
    Hash strHash(s);

    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        int prefix = strHash.calHash(0, i - 1);
        int suffix = strHash.calHash(n - i, n - 1);
        if (prefix == suffix)
        {
            maxLen = i;
        }
    }
    return s.substr(0, maxLen);
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;
    string ans = LPS(s);
    if (ans.size() == 0)
        cout << "No prefix equal suffix found for " << s << endl;
    else
        cout << "Longest prefix equal suffix for " << s << ": " << ans << endl;
}