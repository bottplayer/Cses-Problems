#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll inf=1e18;
int main(){
    //tc 3 truncated due to compile online accepted 
    ll n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>>adjmat(n+1,vector<ll>(n+1,inf));
    for(ll i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adjmat[a][b]=min(adjmat[a][b],c);
        adjmat[b][a]=min(adjmat[b][a],c);
    }
    for(ll i=1;i<=n;i++){
        adjmat[i][i]=0;
    }
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                if(adjmat[i][k]==inf&&adjmat[k][j]==inf)continue;
                adjmat[i][j]=min(adjmat[i][j],adjmat[i][k]+adjmat[k][j]);
            }
        }
    }
    for(ll i=0;i<q;i++){
        ll a,b;
        cin>>a>>b;
        if(adjmat[a][b]>=inf)cout<<-1<<endl;
        else cout<<adjmat[a][b]<<endl;
    }
    return 0;
}