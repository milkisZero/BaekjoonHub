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

    ll v, m;
    cin >> v >> m;

    vector<pll> edge[105];

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    ll s, d;
    cin >> s >> d;

    auto dijkstra = [&](ll st, ll ed, vector<pll> edge[]) {
        priority_queue<pll> pq;
        pq.push({0, st});

        vector<ll> dist(v + 5, INF);
        dist[st] = 0;

        while (!pq.empty()) {
            auto [val, node] = pq.top();
            pq.pop();
            val = -val;

            if (dist[node] == val) {
                for (auto [next, k] : edge[node]) {
                    if (dist[next] > val + k) {
                        dist[next] = val + k;
                        pq.push({-dist[next], next});
                    }
                }
            }
        }
        return dist;
    };

    auto res1 = dijkstra(s, d, edge);
    auto res2 = dijkstra(d, s, edge);

    ll mini = INF;
    for (int i = 1; i <= v; i++) {
        if (i == s || i == d) continue;
        mini = min(mini, res1[i] + res2[i]);
    }

    ll idx = LLINF;
    ll jh_mini = LLINF;
    for (int i = 1; i <= v; i++) {
        if (i == s || i == d) continue;
        if (res1[i] + res2[i] == mini && res1[i] <= res2[i]) {
            if (idx == LLINF) idx = i, jh_mini = res1[i];
            else {
                if (jh_mini > res1[i]) idx = i, jh_mini = res1[i];
                else if (jh_mini == res1[i] && idx > i) idx = i;
            }
        }
    }

    cout << (idx == LLINF ? -1 : idx);

    return 0;
}