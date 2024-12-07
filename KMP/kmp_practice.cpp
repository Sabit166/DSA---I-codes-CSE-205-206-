#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string pat,int *lps,int n);
void KMPSearch(string text, string pattern)
{
    int m = text.size();
    int n = pattern.size();
    int lps[n];
    computeLPSArray(pattern, lps, n);
    for(int i = 0;i < n;i++) cout << lps[i] << ' ';

    int i = 0;
    int j = 0;

    while(i < m)
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j == 0) i++;
            else j = lps[j - 1];
        }
        if(j == n) cout << "\nPattern found at index " << i - j;
    }
}

void computeLPSArray(string pat,int *lps,int n)
{
    int len = 0,j=1;
    lps[0] = 0;
    while(j < n)
    {
        if(pat[j] == pat[len])
        {
            len++;
            lps[j] = len;
            j++;
        }
        else
        {
            if(len == 0) 
            {
                lps[j] = 0;
                j++;
            }
            else len = lps[len - 1];
        }
    }
}

int main()
{
    string text,pattern;
    cout << "Enter Text: ";
    cin >> text;
    cout << "\nEnter Pattern: ";
    cin >> pattern;
    KMPSearch(text, pattern);
}