#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ll n,q;
    cin>>n>>q;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)cin>>v[i];
    vector<ll>prefix(n+1,0);
    prefix[0]=v[0];
    for(ll i=1;i<n;i++){
        prefix[i]=prefix[i-1]+v[i];
    }
    while(q--){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        if(a-1>=0)cout<<prefix[b]-prefix[a-1]<<endl;
        else cout<<prefix[b]<<endl;
    }
    return 0;
}