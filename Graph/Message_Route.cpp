#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<bool>visited(n,false);
    vector<int>dist(n,INT_MAX);
    vector<int>parent(n,-1);
    parent[0]=0;
    pq.push({0,0});//cost , currnode ;
    visited[0]=true;
    dist[0]=0;
    while(!pq.empty()){
        auto c=pq.top();
        int cost=c.first;
        int node=c.second;
        pq.pop();
        for(int neighbour: adj[node]){
            if(visited[neighbour])continue;
            if(cost+1>=dist[neighbour])continue;
            dist[neighbour]=cost+1;
            parent[neighbour]=node;
            visited[neighbour]=true;
            pq.push({cost+1,neighbour});
        }
    }
    vector<int>path;
    int current=n-1;
    while(parent[current]!=-1){
        if(parent[current]==current){
            path.push_back(current);
            break;
        }
        else {
            path.push_back(current);
            current=parent[current];
        }
    }
    reverse(path.begin(),path.end());
    if(path.size()==0||path[0]!=0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<path.size()<<endl;
    for(int p:path){
        cout<<p+1<<" ";
    }cout<<endl;
    return 0;
}