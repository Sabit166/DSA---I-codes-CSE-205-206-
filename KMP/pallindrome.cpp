#include <iostream>
#include <string>

using namespace std;

int lps[100];

void computeLPSArray(string pat, int M, int* lps) {
    int len = 0;
    lps[0] = 0; // lps[0] is always 0

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

bool isPalindrome(string s) {
    int n = s.length();

    // Compute LPS table
    computeLPSArray(s, n, lps);

    // Check if the entire string is a palindrome
    return n == lps[n - 1] + 1;
}

int main() {
    string s = "abcdcba";
    cout << isPalindrome(s) << endl; // Output: True

    return 0;
}