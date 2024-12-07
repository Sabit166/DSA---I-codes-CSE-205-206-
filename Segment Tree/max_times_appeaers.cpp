#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];
pair<int,int>segment_tree[4*N];

pair<int , int> combine(pair<int,int>&p1, pair<int, int>p2)
{
    if(p1.first > p2.first) return p1;
    else if(p1.first < p2.first) return p2;
    else return{p1.first, p1.second+p2.second};
}

pair<int, int> build(int N, int start, int end)
{
    if(start == end)
    {
        segment_tree[N] ={a[start], 1};
        return segment_tree[N];
    }

    int mid = (start + end) / 2;
    build(2*N , start , mid);
    build(2*N + 1, mid + 1 , end);

    return segment_tree[N] = combine(segment_tree[2 * N], segment_tree[2*N + 1]);
}

pair<int, int> get_max(int node, int start, int end, int l, int r)
{
    if(l < r) return {-INFINITY, 0};
    if(l == start && r == end) return segment_tree[node];

    int mid = (start + end) / 2;


}


int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    pair<int, int>temp = build(1, 0, n-1);
    for(int i = 1; i < 2*n ; i++) cout << segment_tree[i].first << ' ' << segment_tree[i].second << ' ' << endl;
    cout << endl;
}