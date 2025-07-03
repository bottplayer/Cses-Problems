#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
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
=======
int main(){
    long long n,m;
    cin>>n>>m;
    vector<vector<long long>>adj(n+1);
    vector<long long>indegree(n+1,0),topo;
    for(long long i=0;i<m;i++){
        long long u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<long long>q;
    for(long long i=1;i<=n;i++){
        if(indegree[i]==0){
            topo.push_back(i);
            q.push(i);
        }
    }
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto it: adj[curr]){
            indegree[it]--;
            if(indegree[it]==0){
                topo.push_back(it);
                q.push(it);
            }
        }
    }
    vector<long long>dist(n+1,LLONG_MIN);
    vector<long long>parent(n+1,-1);
    dist[1]=0;
    for(auto t: topo){
        for(auto it : adj[t]){
            if(dist[it]<dist[t]+1){
                dist[it]=dist[t]+1;
                parent[it]=t;
            }   
        }
    }
    if(dist[n]==LLONG_MIN){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        long long node=n;
        vector<long long>res;
        res.push_back(node);
        while(node!=-1){
            node=parent[node];
            if(node!=-1)res.push_back(node);
        }
        reverse(res.begin(),res.end());
        if(res[0]!=1){
            cout<<"IMPOSSIBLE"<<endl;
        }else{
            cout<<res.size()<<endl;
            for(auto r: res){
                cout<<r<<" ";
            }cout<<endl;
        }
>>>>>>> recover-move-ahead2
    }
    return 0;
}