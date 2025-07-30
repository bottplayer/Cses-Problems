#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll memo(ll n, vector<ll> &dp){
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    ll w = 0;
    for (int i = 1; i <= 6; i++)
        w = (w + memo(n - i, dp)) % mod;

    return dp[n] = w;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> dp(n + 1, -1);

    cout << memo(n, dp) << endl;
    return 0;
}
