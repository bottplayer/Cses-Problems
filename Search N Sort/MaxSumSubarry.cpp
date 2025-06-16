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
   int n;
   cin>>n;
   vector<ll>v(n);
   ll curr_max=0,glob_max=INT_MIN;
   for(int i=0;i<n;i++){
    cin>>v[i];
    curr_max=max(curr_max+v[i],v[i]);
    glob_max=max(glob_max,curr_max);
    // cout<<glob_max<<" ";
   }
   cout<<glob_max<<endl;
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
