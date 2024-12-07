/*
* author: Saifur Rahman
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)

vector<vector<ll>> Graph;

bool topologicalSort(vector<ll> &sequence, ll V) {
  // calculate indegree
  vector<ll> indegree(V+1);
  for(int i=1;i<=V;i++) {
    for(auto it: Graph[i]) {
      indegree[it]++;
    }
  }
  
  queue<ll> q;
  for(int i=1;i<=V;i++) if(indegree[i] == 0) q.push(i);
  if(q.size() == 0) return false;
  while(!q.empty()) {
    ll cur = q.front();
    q.pop();
    sequence.push_back(cur);
    for(auto it: Graph[cur]) {
      indegree[it]--;
      if(indegree[it] == 0) {
        q.push(it);
      }
    }
  }
  if(sequence.size() == V) return true;
  return false;
}

int main() {
  read;
  write;

  ll V, E;
  cin>>V>>E;
  Graph.resize(V+1);
  for(int i=0;i<E;i++) {
    ll u, v;
    cin>>u>>v; // u->v
    Graph[u].push_back(v);
  }
  /*print Graph*/
  // for(int i=1;i<=V;i++) {
  //   cout<<i<<" -> ";
  //   for(auto it: Graph[i]) {
  //     cout<<it<<" ";
  //   }
  //   cout<<endl;
  // }
  vector<ll> sequence;
  if(topologicalSort(sequence, V)) {
    for(auto it: sequence) {
      cout<<it<<endl;
    }
  }
  else {
    cout<<"Not DAG"<<endl;
  }
 
}