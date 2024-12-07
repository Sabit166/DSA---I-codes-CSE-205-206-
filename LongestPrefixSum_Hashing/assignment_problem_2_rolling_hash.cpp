#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Function to calculate the rolling hash of a substring
int rolling_hash(const string &s, int n, int base, int mod, int i)
{
    int power[n + 1];
    if (i == 0)
    {
        power[0] = 1;
        for (int j = 1; j <= n; j++)
        {
            power[j] = (power[j - 1] * base) % mod;
        }
    }
    if (i == 0)
    {
        int hash = 0;
        for (int j = 0; j < n; j++)
        {
            hash = (hash * base + s[j]) % mod;
        }
        return hash;
    }
    else
    {
        return ((rolling_hash(s, n, base, mod, i - 1) - s[i - 1] * power[n - 1]) * base + s[i + n - 1]) % mod;
    }
}

string removeSpaces(const string &str)
{
    string result;
    for (char c : str)
    {
        if (c != ' ')
        {
            result += c;
        }
    }
    return result;
}

// Function to find common phrases using rolling hash
void find_common_phrases(const string &s1, const string &s2, int n)
{
    int base = 256;
    int mod = 1000000007;

    // Remove spaces and calculate prefix hashes
    string s1_no_spaces = removeSpaces(s1);
    string s2_no_spaces = removeSpaces(s2);
    vector<int> h1 = vector<int>(s1_no_spaces.size() - n + 1);
    vector<int> h2 = vector<int>(s2_no_spaces.size() - n + 1);
    for (int i = 0; i < h1.size(); i++)
    {
        h1[i] = rolling_hash(s1_no_spaces, n, base, mod, i);
    }
    for (int i = 0; i < h2.size(); i++)
    {
        h2[i] = rolling_hash(s2_no_spaces, n, base, mod, i);
    }

    // Create a hash table for s1 using an array
    const int table_size = 100000; // Adjust table size as needed
    int hash_table[table_size][2];
    for (int i = 0; i < table_size; i++)
    {
        hash_table[i][0] = -1;
    }

    for (int i = 0; i < h1.size(); i++)
    {
        int index = h1[i] % table_size;
        while (hash_table[index][0] != -1 && hash_table[index][0] != h1[i])
        {
            index = (index + 1) % table_size;
        }
        hash_table[index][0] = h1[i];
        hash_table[index][1] = i;
    }

    // Find common phrases
    vector<string> common_phrases;
    for (int i = 0; i < h2.size(); i++)
    {
        int index = h2[i] % table_size;
        while (hash_table[index][0] != -1 && hash_table[index][0] != h2[i])
        {
            index = (index + 1) % table_size;
        }
        if (hash_table[index][0] == h2[i])
        {
            int j = hash_table[index][1];
            if (s1_no_spaces.substr(j, n) == s2_no_spaces.substr(i, n))
            {
                common_phrases.push_back(s1_no_spaces.substr(j, n));
            }
        }
    }

    // Sort and print results
    sort(common_phrases.begin(), common_phrases.end());
    if (common_phrases.empty())
    {
        cout << "-1" << endl;
    }
    else
    {
        for (const string &phrase : common_phrases)
        {
            cout << phrase << endl;
        }
    }
}

int main()
{
    string s1, s2;
    int n;
    getline(cin, s1);
    getline(cin, s2);
    cin >> n;
    find_common_phrases(s1, s2, n);
    return 0;
}