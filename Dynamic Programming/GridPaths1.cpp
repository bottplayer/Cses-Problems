#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = 1;
    if (n == 1 && s[0][0] == '*')
        dp[0][0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == 0 && j == 0)
                continue;
            if (s[i][j] == '*')
                continue;
            int upper = 0, left = 0;
            if (i - 1 >= 0)
            {
                if (s[i - 1][j] == '.')
                    upper = dp[i - 1][j] % mod;
            }
            if (j - 1 >= 0)
            {
                if (s[i][j - 1] == '.')
                    left = dp[i][j - 1] % mod;
            }
            dp[i][j] = (upper + left) % mod;
        }
    }
    cout << dp[n - 1][n - 1] << endl;
    return 0;
}