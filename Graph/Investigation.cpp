#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
const ll mod=1e9+7;
const ll INF=1e18;
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    ll n,m;
    cin>>n>>m;
    vector<vector<pll>>adj(n+1);
    for(ll i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<ll>dist(n+1,INF),ways(n+1,0),minft(n+1,LLONG_MAX),maxft(n+1,0);
    priority_queue<pll,vector<pll>,greater<pll>>pq;
    dist[1]=0;
    ways[1]=1;
    minft[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        auto[d,u]=pq.top();
        pq.pop();
        if(d>dist[u])continue;
        for(auto[v,w]:adj[u]){
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                ways[v]=ways[u];
                minft[v]=minft[u]+1;
                maxft[v]=maxft[u]+1;
                pq.push({dist[v],v});
            }
            else if(dist[v]==dist[u]+w){
                ways[v]=(ways[v]+ways[u])%mod;
                minft[v]=min(minft[v],minft[u]+1);
                maxft[v]=max(maxft[v],maxft[u]+1);
            }
        }
    }
    cout<<dist[n]<<" "<<ways[n]<<" "<<minft[n]<<" "<<maxft[n]<<endl;
    return 0;
}
