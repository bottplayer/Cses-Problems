#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>parent,sizes;
ll maxi=1;
ll find(ll x){
    if(parent[x]==x)return x;
    return parent[x]=find(parent[x]);
}

bool unions(ll x,ll y){
    ll a=find(x);
    ll b=find(y);
    if(a==b)return true;
    if(sizes[a]<sizes[b]){
        parent[a]=b;
        sizes[b]+=sizes[a];
        maxi=max(maxi,sizes[b]);
    }else{
        parent[b]=a;
        sizes[a]+=sizes[b];
        maxi=max(maxi,sizes[a]);
    }
    return false;
}
int main(){
    ll n,m;
    cin>>n>>m;
    parent.resize(n+1);
    sizes.resize(n+1,1);
    for(ll i=1;i<=n;i++){
        parent[i]=i;
    }
    ll count=n;
    for(ll i=0;i<m;i++){
        ll u,v;cin>>u>>v;
        if(!unions(u,v))count--;
        cout<<count<<" "<<maxi<<endl;
    }
    return 0;
}
