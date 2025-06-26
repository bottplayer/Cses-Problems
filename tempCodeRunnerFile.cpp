#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define mod 1000000007
int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll>indegree(n+1,0);
    vector<vector<ll>>adj(n+1);
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        indegree[v]++;
    }
    vector<ll>topo;
    queue<ll>q;
    for(ll i=1;i<=n;i++){
        if(indegree[i]==0){
            topo.pb(i);
            q.push(i);
        }
    }
    vector<ll>ways(n+1,0);
    ways[1]=1;
    for(auto t: topo){
        for(auto it: adj[t]){
            ways[it]+=(ways[t])%mod;
        }
    }
    cout<<ways[n]%mod<<endl;
    return 0;
}