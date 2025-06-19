#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1);
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    priority_queue<pair<ll,ll>>pq;
    vector<ll>dist(n+1,0);
    vector<ll>parent(n+1,-1);
    pq.push({0,1});
    while(!pq.empty()){
        ll node = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();
        for(auto it:adj[node]){
            if(dist[it]<cost+1){
                parent[it]=node;
                dist[it]=cost+1;
                pq.push({cost+1,it});
            }
        }   
    }
    if(dist[n]>0){
        ll node=n;
        vector<ll>path;
        while(node!=1){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(node);
        cout<<path.size()<<endl;
        reverse(path.begin(),path.end());
        for(auto it:path)cout<<it<<" ";
        cout<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}