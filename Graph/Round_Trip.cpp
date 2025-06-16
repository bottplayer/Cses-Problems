#include<bits/stdc++.h>
using namespace std;

int dfs(int node, vector<vector<int>>adj, vector<int>visited, bool found, vector<int>path,int parent){
    visited[node]=1;
    for(int neighbour: adj[node]){
        if(!visited[neighbour]){

        }else if(neighbour!=parent){
            
        }

    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool found=false;
    vector<int>mainpath;
    for(int i=0;i<n;i++){
        vector<bool>visited(n,false);
        vector<int>path;
        dfs(i,adj,visited,found,path,i);
        if(found){
            mainpath=path;
            break;
        }
    }
    if(!found){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<mainpath.size()<<endl;
    for(int x: mainpath){
        cout<<x<<" ";
    }cout<<endl;
    return 0;
}