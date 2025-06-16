#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Custom hash for unordered_map with pair
struct pair_hash {
    size_t operator()(const pair<ll, ll>& p) const {
        return hash<ll>()(p.first) ^ (hash<ll>()(p.second) << 1);
    }
};

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    using T = tuple<ll, ll, ll>;  // {cost_so_far, max_edge, node}
    priority_queue<T, vector<T>, greater<T>> pq;
    unordered_map<pair<ll, ll>, ll, pair_hash> mp;

    pq.push({0, 0, 1});  // cost=0, max_edge=0, node=1
    ll ans = LLONG_MAX;

    while (!pq.empty()) {
        auto [cost, maxi, node] = pq.top();
        pq.pop();

        pair<ll, ll> state = {node, maxi};
        if (mp.count(state) && mp[state] <= cost) continue;
        mp[state] = cost;

        if (node == n) {
            ll modified_cost = cost - maxi + (maxi / 2);
            ans = min(ans, modified_cost);
        }

        for (auto& [next, wt] : adj[node]) {
            ll newCost = cost + wt;
            ll newMax = max(maxi, wt);
            pq.push({newCost, newMax, next});
        }
    }

    cout << ans << '\n';
    return 0;
}
