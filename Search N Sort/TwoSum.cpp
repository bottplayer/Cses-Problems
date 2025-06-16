#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,target; cin>>n>>target;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    unordered_map<int,int>um;
    for(int i=0;i<n;i++){
        if(um.find(target-v[i])!=um.end()){
            auto t=um.find(target-v[i]);
            cout<<um[target-v[i]]<<" "<<i+1<<endl;
            return 0;
            // return {v[target-v[i]],i+1};
        }
        um[v[i]]=i+1;
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}