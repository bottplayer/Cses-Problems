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
    parent[a]=b;
    sizes[b]+=sizes[a];
    return false;
}
bool check(ll x,ll y){
    ll a=find(x);
    ll b=find(y);
    if(a==b)return true;
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
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        unions(u,v);
    }
    set<ll>par;
    for(ll i=1;i<=n;i++){
        par.insert(parent[i]);
    }
    if(par.size()>=2){
        cout<<"NO"<<endl;
        int count=0;
        for(int x: par){
            cout<<x;
            count++;
            if(count==2)break;
            cout<<" ";
        }
    }else{
        cout<<"YES"<<endl;
    }
    return 0;
}