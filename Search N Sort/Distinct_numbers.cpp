#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin>>n; int arr[n]; 
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n); int ans=1;
    for(int i=0;i<n-1;i++){
        if(arr[i]!=arr[i+1]){
            ans++;
        }
    }
    cout<<ans<<"\n";
}