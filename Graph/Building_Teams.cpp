#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>team(n,0);
    bool flag=1;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        if(team[x]==0&&team[y]==0){
            team[x]=1;
            team[y]=2;
            continue;
        }
        else if(team[x]==team[y]&&team[x]!=0&&team[y]!=0){
            flag=0;
            continue;
        }
        else if(team[x]!=team[y]&&team[x]!=0&&team[y]!=0){
            continue;
        }
        else if(team[x]==1){
            team[y]=2;
        }
        else if(team[x]==2){
            team[y]=1;
        }
        else if(team[y]==1){
            team[x]=2;
        }
        else if(team[y]==2){
            team[x]=1;
        }
        // cout<<team[x]<<" "<<team[y]<<" ";
    }
    if(!flag){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        cout<<team[i]<<" ";
    }cout<<endl;
    return 0;
}