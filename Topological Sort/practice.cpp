#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>>&adj, vector<int>&indegree)
{
    vector<int>topo;
    queue<int>qu;
    for(int i=1;i<indegree.size();i++)
    {
        if(!indegree[i]) qu.push(i);
    }

    int temp;
    while(!qu.empty())
    {
        temp = qu.front();
        qu.pop();
        topo.push_back(temp);
        for(auto &it: adj[temp])
        {
            indegree[it]--;
            if(indegree[it] == 0) qu.push(it);
        }
    }
    return topo;
}

int main()
{
    int v,e;
    cout << "Enter the number of vertex: ";
    cin >> v;
    cout << "\nEnter the number of edges: ";
    cin >> e;
    vector<vector<int>>adj(v+1);
    vector<int>indegree(v+1,0);
    int a,b;
    for(int i=0;i<e;i++)
    {
        cout << "\nEnter edge starting vertex: ";
        cin >> a;
        cout << "\nEnter edge ending vertex: ";
        cin >> b;
        indegree[b]++;
        adj[a].push_back(b);
    }

    vector<int>topo = topologicalSort(adj,indegree);

    if(topo.size() != v) cout << "NOT DAG\n";
    else for(auto &it: topo) cout << it << ' ';
}