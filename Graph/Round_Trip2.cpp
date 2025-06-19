#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void dfs(ll node ,ll parent, vector<vector<ll>> &adj, vector<ll>&path, vector<ll>&visited, vector<ll>&par, bool &found){
    if(found)return;
    par[node]=parent;
    visited[node]=true;
    for(auto nnode: adj[node]){
        if(!visited[nnode]){
            dfs(nnode,node,adj,path,visited,par,found);
        }
        else if(visited[nnode]==1){
            vector<ll>temp;
            ll cur=node;
            temp.push_back(nnode);  
            while(cur!=nnode) {
                if (cur==-1)return;
                temp.push_back(cur);
                cur=par[cur];
            }
            temp.push_back(nnode); 
            reverse(temp.begin(),temp.end()); 
            path=temp;
            found=true;
            return;

        }
    }
    visited[node]=2;
    return;
}
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1);
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<ll>visited(n+1,0);
    vector<ll>path;
    vector<ll>parent(n+1,-1);
    bool found=false;
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i,-1,adj,path,visited,parent,found);
            if(found)break;
        }
    }
    if(path.size()==0){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        cout<<path.size()<<endl;
        // reverse(path.begin(),path.end());
        for(auto p: path)cout<<p<<" ";
        cout<<endl;
    }
    return 0;
}