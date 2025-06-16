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
   vector<int>v(n);
   ll sum=0;
   for(int i=0;i<n;i++){
    cin>>v[i];
    sum+=v[i];
   }
   sort(v.begin(),v.end());
//    for(int i=1;i<sum+1;i++){
//     int lo=0,hi=n-1;
//     bool found=0;
//     ll currs=0;
//     while(lo<=hi){
//         if(currs==i||v[lo]==i||v[hi]==i){
//             found=1;
//             break;
//         }
//         else if(currs>i){
//             currs-=v[lo];
//             lo++;
//         }else{
//             currs+=v[hi];
//             hi--;
//         }
//     }
//     if(!found){
//         cout<<i<<endl;
//         return;
//     }
//    }
   ll currsum=0;
    for(int i=0;i<n;i++){
        if(v[i]>currsum+1){
            cout<<currsum+1<<endl;
            return;
        }
        currsum+=v[i];
    }
    cout<<currsum+1<<endl;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; 
    t=1;
    while(t--){
        solve();
    }
}
