#include <bits/stdc++.h>
using namespace std;

bool KMP(string pattern, string text)
{
    int n = pattern.size();
    int m = text.size();

    int lps[n];
    lps[0] = 0;

    int len = 0, j = 1;

    while (j < n)
    {
        if (pattern[len] == pattern[j])
        {
            len++;
            lps[j] = len;
            j++;
        }
        else
        {
            if (len == 0)
            {
                lps[j] = 0;
                j++;
            }
            else
                len = lps[len - 1];
        }
    }

    j = 0;
    int i = 0;

    while (i < m)
    {
        if (j == n)
            return true;

        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }
        else
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
    return false;
}

vector<string> common_phrase(string &s1, string &s2, int n)
{
    set<string> phrases;
    int a = s1.size();
    int b = s2.size();

    for (int i = 0; i <= a - n; i++)
    {
        string substr = s1.substr(i, n);
        if (KMP(substr, s2))
            phrases.insert(substr);
    }
    return vector<string>(phrases.begin(), phrases.end());
}

string removeSpace(const string &s)
{
    string str;
    for (auto &c : s)
    {
        if (c != ' ')
        {
            str += c;
        }
    }
    return str;
}

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    str1 = removeSpace(str1);
    str2 = removeSpace(str2);

    int length;
    cin >> length;

    if (str1.empty() || str2.empty() || length > str1.size() || length > str2.size())
    {
        cout << -1 << endl;
        return 0;
    }

    vector<string> phrases = common_phrase(str1, str2, length);

    if (phrases.empty())
    {
        cout << -1;
    }
    else
    {
        for (auto &phrase : phrases)
        {
            cout << phrase << endl;
        }
    }

    return 0;
}