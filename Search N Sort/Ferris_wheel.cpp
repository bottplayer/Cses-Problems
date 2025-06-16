#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int lo=0,hi=n-1;
    int c=0;
    while(lo<=hi){
        if(lo==hi){
            c++;
            break;
        }
        else{
            if(v[lo]+v[hi]<=x){
                c++;
                lo++;
                hi--;
            }
            else{
                c++;
                hi--;
            }
        }
    }
    cout<<c<<endl;
    return 0;
}