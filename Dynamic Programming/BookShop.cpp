#include <bits/stdc++.h>
using namespace std;
int memoise(int ind, int n, int balance, vector<int> &rupees, vector<int> &pages, vector<int> &dp)
{
    if (ind == n)
    {
        return 0;
    }
    if (dp[ind] != -1)
        return dp[ind];
    int include = 0;
    int exclude = memoise(ind + 1, n, balance, rupees, pages, dp);
    if (balance >= rupees[ind])include = pages[ind] + memoise(ind + 1, n, balance - rupees[ind], rupees, pages, dp);
    // cout << max(include, exclude) << endl;
    return dp[ind] = max(include, exclude);
}
int main()
{
    int n, balance;
    cin >> n >> balance;
    vector<int> rupees(n), pages(n);
    for (int i = 0; i < n; i++)
        cin >> rupees[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];
    vector<int> dp(n + 1, -1);
    cout << memoise(0, n, balance, rupees, pages, dp);
    return 0;
}