#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int SegmentTree[2 * N];
int build(int node, int start, int end)
{
    if (start == end)
    {
        SegmentTree[node] = a[start];
        return SegmentTree[node];
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    SegmentTree[node] = SegmentTree[2*node]+SegmentTree[2*node+1];
    //SegmentTree[node] = min(SegmentTree[2 * node], SegmentTree[2 * node + 1]);
    // cout<<max(SegmentTree[2*node]<<endl;
}
int query(int node, int start, int end, int l, int r)
{
    if (start > r || end < l)
    {
        return 0;
    }
    if (l <= start && end <= r)
    {
        return SegmentTree[node];
    }
    int mid = (start + end) / 2;
    int q1 = query(2 * node, start, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, end, l, r);
    return q1 + q2;
}
void update(int node, int start, int end, int val, int idx)
{
    if (start == end)
    {
        a[start] = val;
        SegmentTree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid)
    {
        update(2 * node, start, mid, val, idx);
    }
    else
    {
        update(2 * node + 1, mid + 1, end, val, idx);
    }
    SegmentTree[node] = SegmentTree[2 * node] + SegmentTree[2 * node + 1];
}
void find_min_oc(int node, int start, int end, pair<int, int> &p)
{
    if (SegmentTree[node] == p.first)
    {
        p.second++;
    }
    if (start == end)
        return;
    int mid = (start + end) / 2;
    find_min_oc(2 * node, start, mid, p);
    find_min_oc(2 * node + 1, mid + 1, end, p);
}
void find_min_oc_idx(int node, int start, int end, pair<int, int> &p, int cnt, int &idx)
{
    if (SegmentTree[node] == p.first)
    {
        p.second++;
        if (p.second == cnt)
        {
            idx = node;
        }
    }
    if (start == end)
        return;
    int mid = (start + end) / 2;
    find_min_oc_idx(2 * node, start, mid, p, cnt, idx);
    find_min_oc_idx(2 * node + 1, mid + 1, end, p, cnt, idx);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    for (int i = 1; i <= 2 * n; i++)
    {
        cout << SegmentTree[i] << " ";
    }
    cout << endl;
    //  int l,r;
    //  cin>>l>>r;
    //  int ans = query(1,0,n-1,l,r);
    //  cout<<ans<<endl;
    //  int idx,val;
    //  cin>>val>>idx;
    //  update(1,0,n-1,val,idx);
    pair<int, int> p = {SegmentTree[1], 0};
    int idx = -1;
    find_min_oc_idx(1, 0, n - 1, p, 2, idx);
    cout << p.second << " " << idx << endl;
}