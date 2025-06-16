#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<ll,ll>>>adj(n+1);
    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vector<bool>visited(n+1,false);
    queue<pair<ll,ll>>q;
    vector<ll>v;
    q.push({1,0});
    while(!q.empty()){
        auto curr=q.front();
        q.pop();
        ll node=curr.first;
        ll cost=curr.second;
        if(visited[node])continue;
        visited[node]=true;
        for(auto it: adj[node]){
            ll nnode=it.first,wt=it.second;
            q.push({nnode,cost+wt});
            if(nnode==n){
                if(v.size()<k){
                    v.push_back(cost+wt);
                    sort(v.begin(),v.end());
                }else{
                    if(v.back()>cost+wt){
                        v.pop_back();
                        v.push_back(cost+wt);
                    }
                    sort(v.begin(),v.end());
                }
            }
        }
    }
    for(ll va:v){
        cout<<va<<" ";
    }cout<<endl;
    return 0;
}