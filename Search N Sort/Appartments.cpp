#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); 
    int n,m,k; cin>>n>>m>>k;
    int a[n],b[m];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    int i=0,j=0; int ans=0;
    while(i<n && j<m){
        if(abs(b[j]-a[i])<=k){
            ans++;
        j++; i++;
        }
        else{
            if(a[i]-b[j]>k){
                j++;
            }
            else{
                i++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}