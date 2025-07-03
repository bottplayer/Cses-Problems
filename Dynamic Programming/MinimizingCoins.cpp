#include <bits/stdc++.h>
using namespace std;

int memoise(int sum, vector<int> &v, vector<int> &dp)
{
    if (sum == 0)
        return 0;
    if (sum < 0)
        return INT_MAX;
    if (dp[sum] != -1)
        return dp[sum];

    int ans = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        int res = memoise(sum - v[i], v, dp);
        if (res != INT_MAX)
            ans = min(ans, 1 + res);
    }
    return dp[sum] = ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> dp(k + 1, -1);
    int res = memoise(k, v, dp);
    cout << (res == INT_MAX ? -1 : res) << endl;
    return 0;
}
