#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<pll>> adj(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<ll> count(n + 1, 0);
    vector<ll> res;
    pq.push({0, 1});
    while (!pq.empty())
    {
        ll currnode = pq.top().second, currcost = pq.top().first;
        pq.pop();
        if (count[currnode] > k)
            continue;
        count[currnode]++;
        if (currnode == n)
        {
            res.push_back(currcost);
            if (count[n] == k)
                break;
        }
        for (auto it : adj[currnode])
        {
            ll nextnode = it.first, weight = it.second;
            pq.push({currcost + weight, nextnode});
        }
    }
    for (ll r : res)
        cout << r << " ";
    cout << endl;
    return 0;
}
