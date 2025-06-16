#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>adj(n);
    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        u--; v--;
        adj[u].push_back({v,w});
        // adj[v].push_back({u,w});
    }
    //dijikstra using pq
    vector<bool>visited(n,false);
    vector<ll>distance(n,LLONG_MAX);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,0}); 
    distance[0]=0;
    while(!pq.empty()){
        ll node=pq.top().second;
        ll cost= pq.top().first;
        pq.pop();
        if(visited[node])continue;
        visited[node]=true;
        for(auto nieghbour:adj[node]){
            ll nnode=nieghbour.first;
            ll val=nieghbour.second;
            // if(!visited[nnode]){
                if(distance[nnode]>cost+val){
                    distance[nnode]=cost+val;
                    pq.push({distance[nnode],nnode});
                }
            // }
            // else if(distance[nnode]>cost+val){
            //     distance[nnode]=cost+val;
            //     pq.push({distance[nnode],nnode});
            // }
        }
    }
    for(ll i=0;i<n;i++){
        cout<<distance[i]<<" ";
    }cout<<endl;
    return 0;
}