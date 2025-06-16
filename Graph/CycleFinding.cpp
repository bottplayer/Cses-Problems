// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// void dfs(int node, vector<vector<ll>> &adj, vector<bool> &visited, int parent, vector<ll> &path, vector<ll> &par, bool &found)
// {
//     if (found)
//         return;
//     visited[node] = true;
//     par[node] = parent;
//     for (auto it : adj[node])
//     {
//         if (!visited[it])
//         {
//             dfs(it, adj, visited, node, path, par, found);
//         }
//         else if (parent != it && !found)
//         {
//             found = 1;
//             ll cur = node;
//             path.push_back(it);
//             while (cur != it)
//             {
//                 path.push_back(cur);
//                 cur = par[cur];
//             }
//             path.push_back(it);
//             return;
//         }
//     }
// }
// int main()
// {
//     ll n, m;
//     cin >> n >> m;
//     vector<vector<ll>> adj(n + 1);
//     vector<vector<ll>> edges;
//     for (int i = 0; i < m; i++)
//     {
//         ll u, v, w;
//         cin >> u >> v >> w;
//         adj[u].push_back(v);
//         edges.push_back({u, v, w});
//     }
//     vector<ll> dist(n + 1, LLONG_MAX);
//     dist[1] = 0;
//     for (int i = 1; i <= n - 1; i++)
//     {
//         for (auto edge : edges)
//         {
//             int u = edge[0], v = edge[1], w = edge[2];
//             if (dist[u] != LLONG_MAX && dist[v] > dist[u] + w)
//             {
//                 dist[v] = dist[u] + w;
//             }
//         }
//     }
//     bool found = false;
//     int node = -1;
//     for (auto edge : edges)
//     {
//         int u = edge[0], v = edge[1], w = edge[2];
//         if (dist[u] != LLONG_MAX && dist[v] > dist[u] + w)
//         {
//             found = true;
//             node = v;
//             break;
//         }
//     }
//     if (!found)
//     {
//         cout << "NO" << endl;
//     }
//     else
//     {
//         vector<bool> visited(n + 1, false);
//         vector<ll> path;
//         vector<ll> par(n + 1, -1);
//         bool f = false;
//         dfs(node, adj, visited, -1, path, par, f);
//         reverse(path.begin(), path.end());
//         cout << "YES" << endl;
//         for (auto p : path)
//         {
//             cout << p << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges;

    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<ll> dist(n + 1, 0); // we can initialize to 0 rather than of LLONG_MAX
    vector<ll> par(n + 1, -1);
    ll x = -1;

    for (int i = 1; i <= n; ++i)
    {
        x = -1;
        for (auto edge : edges)
        {
            ll u = edge[0], v = edge[1], w = edge[2];
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                par[v] = u;
                x = v;
            }
        }
    }

    if (x == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        // go n steps back to know that inside the cycle
        for (int i = 0; i < n; ++i)
        {
            x = par[x];
        }

        vector<ll> cycle;
        ll cur = x;
        do
        {
            cycle.push_back(cur);
            cur = par[cur];
        } while (cur != x);
        cycle.push_back(x);
        reverse(cycle.begin(), cycle.end());

        cout << "YES" << endl;
        for (ll node : cycle)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
