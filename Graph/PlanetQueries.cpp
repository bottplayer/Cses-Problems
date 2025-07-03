#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const ll LOG=30;
int main(){
    ll n,q;
    cin>>n>>q;
    vector<ll>adj(n+1);
    for(ll i=1;i<=n;i++){
        cin>>adj[i];
    }
    for(ll i=0;i<q;i++){
        ll x,k;
        cin>>x>>k;
        ll top=x;
        while(k--){
            top=adj[top];
        }
        cout<<top<<endl;
    }
    return 0;
}