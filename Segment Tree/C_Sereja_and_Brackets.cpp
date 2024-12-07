#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
string s;
struct Node {
    int open, close; // open: unmatched '(', close: unmatched ')'
} segmenttree[4 * N];

void build(int node, int start, int end) {
    if (start == end) {
        if (s[start] == '(') {
            segmenttree[node] = {1, 0}; // One unmatched '('
        } else {
            segmenttree[node] = {0, 1}; // One unmatched ')'
        }
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    // Combine two halves
    int match = min(segmenttree[2 * node].open, segmenttree[2 * node + 1].close);
    segmenttree[node].open = segmenttree[2 * node].open + segmenttree[2 * node + 1].open - match;
    segmenttree[node].close = segmenttree[2 * node].close + segmenttree[2 * node + 1].close - match;
}

pair<int, int> querry(int node, int start, int end, int left, int right) {
    if (start > right || end < left) {
        return {0, 0}; // Return empty result
    }
    if (start >= left && end <= right) {
        return {segmenttree[node].open, segmenttree[node].close};
    }
    int mid = (start + end) / 2;
    pair<int, int> q1 = querry(2 * node, start, mid, left, right);
    pair<int, int> q2 = querry(2 * node + 1, mid + 1, end, left, right);

    // Combine two halves
    int match = min(q1.first, q2.second);
    int total_open = q1.first + q2.first - match;
    int total_close = q1.second + q2.second - match;
    return {total_open, total_close};
}

int main() {
    cin >> s;
    int t, a, b, sz = s.size();
    cin >> t;
    build(1, 0, sz - 1);
    while (t--) {
        cin >> a >> b;
        --a, --b; // Adjust to 0-based indexing
        pair<int, int> res = querry(1, 0, sz - 1, a, b);
        // Each complete matching pair contributes 2 to the length of valid sequence
        int valid_length = (b - a + 1) - res.first - res.second;
        cout << valid_length << "\n";
    }
}
