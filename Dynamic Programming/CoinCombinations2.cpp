#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int memoise(int ind, int sum, int x, int prev, vector<int> &v, vector<vector<int>> &dp)
{
    if (ind >= v.size() || sum > x)
        return 0;
    if (sum == x)
        return 1;
    if (dp[ind][sum] != -1)
        return dp[ind][sum];
    int ways = 0;
    if (prev == -1 || prev <= v[ind])
    {
        ways += memoise(ind + 1, sum, x, prev, v, dp);
    }
    if (sum + v[ind] <= x && (prev == -1 || prev <= v[ind]))
    {
        ways += memoise(ind + 1, sum + v[ind], x, v[ind], v, dp);
        ways += memoise(ind, sum + v[ind], x, v[ind], v, dp);
    }
    return dp[ind][sum] = ways % mod;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
    int ans = memoise(0, 0, x, -1, v, dp);
    cout << ans << endl;
    return 0;
}