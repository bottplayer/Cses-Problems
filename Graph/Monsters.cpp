#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>m>>n;
    vector<string>map(m);
    for(int i=0;i<m;i++){
        cin>>map[i];
    }
    vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
    queue<pair<int,pair<int,int>>>q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]=='M'){
                q.push({0,{i,j}});
                dist[i][j]=0;
            }
        }
    }
    int x[4]={0,0,-1,+1};
    int y[4]={-1,+1,0,0};
    char ch[4]={'L','R','U','D'};
    vector<vector<bool>>visited(m,vector<bool>(n,0));
    while(!q.empty()){
        int cost=q.front().first;
        int currx=q.front().second.first;
        int curry=q.front().second.second;
        q.pop();
        if(dist[currx][currx]>cost)dist[currx][curry]=cost;
        for(int i=0;i<4;i++){
            int newx=currx+x[i];
            int newy=curry+y[i];
            if(newx>=0&&newx<m&&newy>=0&&newy<n){
                if(map[newx][newy]=='.'&&!visited[newx][newy]){
                    visited[newx][newy]=true;
                    q.push({cost+1,{newx,newy}});
                }
            }
        }
    }
    //i,j,count,patharr
    queue<pair<vector<int>,vector<int>>>q2;
    vector<vector<bool>>visited2(m,vector<bool>(n,false));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]=='A'){
                q2.push({{i,j,0},{}});
                visited[i][j]=1;
            }
        }
    }
    bool found=false;
    while(!q2.empty()){ 
        auto cont=q2.front().first;
        int currx=cont[0],curry=cont[1],count=cont[2];
        auto path=q2.front().second;
        if(currx==0||curry==0||currx==m-1||curry==n-1){
            found=true;
            cout<<"YES"<<endl;
            cout<<path.size()<<endl;
            for(char chhh: path){
                cout<<chhh;
            }
            cout<<endl;
            break;
        }
        q2.pop();
        for(int i=0;i<4;i++){
            int newx=currx+x[i],newy=curry+y[i];
            char newc=ch[i];
            if(newx>=0&&newx<m&&newy>=0&&newy<n){
                if(map[newx][newy]=='.'&&!visited2[newx][newy]){
                    if(dist[newx][newy]<=count+1)continue;
                    visited2[newx][newy]=true;
                    auto newpath=path;
                    newpath.push_back(newc);
                    q2.push({{newx,newy,count+1},newpath});
                }
            }
        }
    }
    if(!found){
        cout<<"NO"<<endl;
    }
    return 0;
}