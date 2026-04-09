#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

int main() {
    fastio;

    while (1) {
        ll n, m;
        cin >> n >> m;

        if (!n && !m) return 0;

        ll s, d;
        cin >> s >> d;

        vector<pll> edge[505], edge2[505];

        for (int i = 0; i < m; i++) {
            ll u, v, p;
            cin >> u >> v >> p;
            edge[u].push_back({v, p});
            edge2[v].push_back({u, p});
        }

        auto dijkstra = [&](ll st, ll ed, vector<pll> edge[]) {
            priority_queue<pll> pq;
            pq.push({0, st});

            vector<ll> dist(n, LLINF);
            dist[st] = 0;

            while (!pq.empty()) {
                auto [val, node] = pq.top();
                pq.pop();
                val = -val;

                if (dist[node] == val) {
                    for (auto [next, k] : edge[node]) {
                        if (dist[next] > val + k) {
                            dist[next] = val + k;

                            if (next != ed) pq.push({-dist[next], next});
                        }
                    }
                }
            }
            return dist;
        };

        auto res1 = dijkstra(s, d, edge);
        auto res2 = dijkstra(d, s, edge2);

        vector<pll> g[505];
        for (int i = 0; i < n; i++) {
            for (auto [next, val] : edge[i]) {
                if (res1[i] + val + res2[next] != res1[d]) {
                    g[i].push_back({next, val});
                }
            }
        }

        auto ans = dijkstra(s, d, g);
        cout << (ans[d] == LLINF ? -1 : ans[d]) << '\n';
    }

    return 0;
}