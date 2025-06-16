// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int n,m; cin>>n>>m;
//     vector<int>tic(n),cust(m);
//     map<int,int>mp;
//     for(int i=0;i<n;i++){
//         cin>>tic[i];
//         mp[tic[i]]++;
//     }
//     for(int  i=0;i<m;i++){
//         cin>>cust[i];
//     }
//     sort(tic.begin(),tic.end());
//     for(int i=0;i<m;i++){
//         auto index=lower_bound(tic.begin(),tic.end(),cust[i]);
//         if(index==tic.end()){
//             if(tic.back()<=cust[i]){
//                 if(mp[tic.back()]>0){
//                     cout<<tic.back()<<endl;
//                     mp[tic.back()]--;
//                 }
//                 else{
//                     cout<<-1<<endl;
//                 }
//             }
//             else{
//                 cout<<-1<<endl;
//             }
//         }
//         else if(index==tic.begin()){
//             if(*index<=cust[i]){
//                 if(mp[*index]>0){
//                     cout<<*index<<endl;
//                     mp[*index]--;
//                 }
//                 else{
//                     cout<<-1<<endl;
//                 }
//             }
//             else{
//                 cout<<-1<<endl;
//             }
//         }
//         else{
//             if(*index>cust[i])index--;
//             if(mp[*index]>0){   
//                 cout<<*index<<endl;
//                 mp[*index]--;
//             }
//             else{
//                 cout<<-1<<endl;
//             }
//         }
        
//     }
//     return 0;
// }
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, m, h, t;
    multiset<int> prices;
 
    cin >> n >> m;
 
    for (int i = 0; i < n; i++) {
        cin >> h;
        prices.insert(-h);
    }
 
    for (int i = 0; i < m; i++) {
        cin >> t;
        auto it = prices.lower_bound(-t);
        if (it == prices.end()) {
            cout << "-1\n";
        } else {
            cout << -(*it) << "\n";
            prices.erase(it);
        }
    }
 
    return 0;
}
