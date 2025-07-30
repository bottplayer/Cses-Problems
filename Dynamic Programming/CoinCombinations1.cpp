#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll memoise(ll ind, ll sum, ll x, vector<ll> &v, vector<vector<ll>> &dp)
{
    if (ind >= v.size() || sum > x)
        return 0;
    if (sum == x)
        return 1;
    if (dp[ind][sum] != -1)
        return dp[ind][sum];
    ll ways = 0;
    // ways += memoise(ind + 1, sum, x, v, dp);
    ways += memoise(ind + 1, sum, x, v, dp);
    for (int i = 0; i < v.size(); i++)
    {
        ways += memoise(ind, sum + v[ind], x, v, dp);
    }
    return dp[ind][sum] = ways % mod;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(x + 1, -1));
    ll ans = memoise(0, 0, x, v, dp);
    cout << ans << endl;
    return 0;
}