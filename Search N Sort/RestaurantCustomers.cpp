#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define upd upper_bound
#define lpd lower_bound
#define pb push_back
#define endl "\n"
#define f(i,a,b) for(ll i = a;i<=b;i++)
#define ff(i,a,b) for(ll i=a ;i>=b;i--)
#define mod 1000000007
void solve(){
   
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // int t; cin>>t;
    // while(t--){
    //     solve();
    // }
    ll n;
    cin>>n;
    vector<ll>v(1000000009);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v[a-1]++;
        v[b-1]--;
    }
    
    ll ans=0;
    ll c=0;
    for(auto x: v){
        c+=x;
        ans=max(ans,c);
    }
    cout<<ans<<endl;
}
