#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<array<ll, 3>> edges;
    vector<vector<ll>> adj(n + 1), rev_adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    vector<ll> dist(n + 1, -INF);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (auto &[u, v, w] : edges)
        {
            if (dist[u] != -INF && dist[v] < dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    vector<bool> reachable_from_1(n + 1, false);
    function<void(ll)> dfs1 = [&](ll u)
    {
        reachable_from_1[u] = true;
        for (ll v : adj[u])
        {
            if (!reachable_from_1[v])
                dfs1(v);
        }
    };
    dfs1(1);

    vector<bool> reachable_to_n(n + 1, false);
    function<void(ll)> dfs2 = [&](ll u)
    {
        reachable_to_n[u] = true;
        for (ll v : rev_adj[u])
        {
            if (!reachable_to_n[v])
                dfs2(v);
        }
    };
    dfs2(n);

    for (auto &[u, v, w] : edges)
    {
        if (dist[u] != -INF && dist[v] < dist[u] + w)
        {
            if (reachable_from_1[v] && reachable_to_n[v])
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << dist[n] << endl;
    return 0;
}
