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

vector<ll> adj[505];
ll indegree[505];
ll times[505];
ll n;
ll res[505];

void bfs_topo() {
    queue<ll> q;
    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) {
            q.push(i);
            res[i] = times[i];
        }
    }

    while (!q.empty()) {
        ll a = q.front();
        q.pop();

        for (int i = 0; i < adj[a].size(); i++) {
            ll next = adj[a][i];
            indegree[next]--;

            res[next] = max(res[next], res[a] + times[next]);

            if (!indegree[next]) q.push(next);
        }
    }
}

int main() {
    fastio;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        ll tmp;
        cin >> tmp;
        times[i] = tmp;

        while (1) {
            cin >> tmp;
            if (tmp == -1) break;

            adj[tmp].push_back(i);
            indegree[i]++;
        }
    }

    bfs_topo();

    for (int i = 1; i <= n; i++) cout << res[i] << endl;

    return 0;
}