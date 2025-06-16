#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define upd upper_bound
#define lpd lower_bound
#define pb push_back
#define endl "\n"
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define ff(i,a,b) for(ll i=a ;i>=b;i--)
#define mod 1000000007
void solve(){
   int n;
   cin>>n;
   vector<int>v(n);
   unordered_map<int,int>um;
   for(int i=0;i<n;i++){
    cin>>v[i];
    um[v[i]]++;
   }
   int freq=INT_MIN,maxi=INT_MIN;
   for(auto x:um){
    if(x.second>freq){
        maxi=x.first;
        freq=x.second;
    }
   }
    sort(v.begin(),v.end());
    int middle=v[n/2];
    ll ans1=0,ans2=0;
    for(int i=0;i<n;i++){
        ans1+=abs(v[i]-middle);
        ans2+=abs(v[i]-maxi);
    }
    // cout<<min(ans1,ans2)<<endl;
    cout<<ans1<<endl;

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; 
    // cin>>t;
    t=1;
    while(t--){
        solve();
    }
}
