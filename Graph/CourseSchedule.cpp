#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1);
    vector<ll>indegree(n+1,0);
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    vector<ll>visited(n+1,false);
    queue<ll>q;
    bool poss=false;
    vector<ll>res;
    for(ll i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
            poss=true;
            res.push_back(i);
            // cout<<i<<" ";
            visited[i]=true;
        }
    }
    if(!poss){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    while(!q.empty()){
        ll node=q.front();
        q.pop();
        for(ll nnode: adj[node]){
            indegree[nnode]--;
            if(indegree[nnode]==0&&!visited[nnode]){
                q.push(nnode);
                // cout<<nnode<<" ";
                res.push_back(nnode);
                visited[nnode]=true;
            }
        }
    }
    if(res.size()<n){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        for(ll r:res){
            cout<<r<<" ";
        }
        cout<<endl;
    }
    return 0;
}