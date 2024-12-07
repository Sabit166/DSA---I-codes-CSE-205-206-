#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int a[N];
int segment_tree[2*N];

int build(int node, int start, int end)
{
    if(start == end)
    {
        segment_tree[node] = a[start];
        return segment_tree[node];
    }
    int mid = (start + end) / 2;
    build(2*node, start, mid);
    build(2*node + 1, mid+1, end);
    segment_tree[node] = segment_tree[2*node] + segment_tree[2*node + 1];
}

int query(int node, int start, int end,  int l, int r)
{
    if(start>=l && end<=r) return segment_tree[node];
    if(start>r || end<l) return 0;

    int mid = (start + end) / 2;

    return query(node, start, mid, l, r) + query(node, mid + 1, end, l, r);
}

void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        a[start] = segment_tree[node] = val;
        return;
    }
    
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i< n;i++)    cin >> a[i];
    build(1, 0, n - 1);
    for(int i=1;i<2*n;i++) cout << segment_tree[i] << ' ';
    cout << endl;
}