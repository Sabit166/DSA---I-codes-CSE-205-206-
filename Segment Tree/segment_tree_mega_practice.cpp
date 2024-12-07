#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N];

class Node
{
    public:
    int mx;
    int mn;

    vector<int>mxit;
    vector<int>mnit;

    Node(){}
    Node(int it, int a)
    {
        mx = mn = a;
        mxit = {it};
        mnit = {it};
    }

    Node(int a, int b, vector<int>&x, vector<int>&y)
    {
        mx = a;
        mn = b;
        mxit = x;
        mnit = y;
    }
};

Node segment_tree[4*N];

Node combine(Node& n1, Node& n2)
{
    int mx, mn;
    vector<int>mxit, mnit;

    mx = max(n1.mx, n2.mx);
    mn = min(n1.mn, n2.mn);

    if(n1.mx > n2.mx) mxit = n1.mxit;

    else if(n1.mx < n2.mx) mxit = n2.mxit;

    else
    {
        mxit = n1.mxit;
        mxit.insert(mxit.end(), n2.mxit.begin(), n2.mxit.end());
    }

    if(n1.mn > n2.mn) mnit = n2.mnit;

    else if(n1.mn < n2.mn) mnit = n1.mnit;

    else
    {
        mnit = n1.mnit;
        mnit.insert(mnit.end(), n2.mnit.begin(), n2.mnit.end());
    }
    Node temp(mx, mn, mxit, mnit);
    return temp;
}

void build(int node, int start, int end)
{
    if(start == end)
    {
        Node temp(start, a[start]);
        segment_tree[node] = temp;
        return;
    }

    int mid = (start + end) / 2;
    build(2*node, start, mid);
    build(2*node + 1, mid + 1, end);

    segment_tree[node] = combine(segment_tree[2*node], segment_tree[2*node+1]);
}


int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    build(1,0,n-1);

    for(int i = 1;i < 2*n ; i++)
    {
        cout << segment_tree[i].mx<< ' ' << segment_tree[i].mn << "   ";
        for(auto &it: segment_tree[i].mxit) cout << it << ' ';
        cout << "   ";
        for(auto &it: segment_tree[i].mnit) cout << it << ' ';
        cout << endl;
    }
}