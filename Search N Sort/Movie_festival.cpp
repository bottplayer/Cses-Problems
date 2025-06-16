// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long 
// #define ld long double
// #define upd upper_bound
// #define lpd lower_bound
// #define pb push_back
// #define endl "\n"
// #define f(i,a,b) for(ll i = a;i<=b;i++)
// #define ff(i,a,b) for(ll i=a ;i>=b;i--)
// #define mod 1000000007
// void solve(){
   
// }
// bool cmp(pair<ll,ll>p1,pair<ll,ll>p2){
//     // if((p2.second-p2.first+1)==(p1.second-p1.first+1)){
//     //     return (p1.first)<=(p2.first);
//     // }
//     // return (p2.second-p2.first+1)>(p1.second-p1.first+1);
//     return p1.second<p2.second;
// }
// int main(){
//     ios::sync_with_stdio(0); cin.tie(0);
//     // int t; cin>>t;
//     // while(t--){
//     //     solve();
//     // }
//     ll n;
//     cin>>n;
//     vector<pair<ll,ll>>v(n);
//     for(ll i=0;i<n;i++){
//         cin>>v[i].first;
//         cin>>v[i].second;
//     }
//     sort(v.begin(),v.end(),cmp);
//     ll ans=0;
//     ll ch=LLONG_MIN;
//     for(ll i=0;i<n;i++){
//         if(v[i].first>=ch&&v[i].second>=ch){
//             ch=v[i].second;
//             ans++;
//         }
//         // cout<<v[i].first<<"->"<<v[i].second<<" ";
//     }
//     cout<<ans<<endl;
//     return 0;
// }
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
bool cmp(pair<int,int>p1,pair<int,int>p2){
    return p1.second-p2.first+1 < p2.second-p2.first+1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // int t; cin>>t;
    // while(t--){
    //     solve();
    // }
    int n;
    cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
        cin>>v[i].second;
    }
    sort(v.begin(),v.end(),cmp);
    int ans=1;
    int ch=v[0].second;
    for(int i=1;i<n;i++){
        if(v[i].first>=ch&&v[i].second>=ch){
            ch=v[i].second;
            ans++;
        }
        // cout<<v[i].first<<"->"<<v[i].second<<" ";
    }
    cout<<ans<<endl;
    return 0;
}