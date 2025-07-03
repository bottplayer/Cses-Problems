#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>adj(n+1);
    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<bool>vis(n+1,false);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,1});
    ll cost=0,edges=0;
    while(!pq.empty()&&edges<n){
        auto [c,u]=pq.top();pq.pop();
        if(vis[u])continue;
        vis[u]=true;
        cost+=c;
        edges++;
        for(auto [v,w]:adj[u]){
            if(!vis[v])pq.push({w,v});
        }
    }
    if(edges==n)cout<<cost<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
