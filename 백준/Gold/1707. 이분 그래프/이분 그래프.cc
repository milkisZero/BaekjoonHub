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

vector<ll> vertex[20005];
ll visited[20005];

bool bfs(ll node) {
    ll tmp = 0;
    for (auto e : vertex[node]) {
        if (visited[e]) {
            if (tmp && tmp != visited[e]) return 0;

            tmp = visited[e];
        }
    }

    if (tmp == 0) visited[node] = 1;
    else visited[node] = -tmp;

    queue<ll> q;
    q.push(node);

    while (!q.empty()) {
        ll cur = q.front();
        q.pop();

        for (auto e : vertex[cur]) {
            if (visited[e] == 0) {
                visited[e] = -visited[cur];
                q.push(e);
            }
            else if (visited[e] == visited[cur]) return 0;
        }
    }

    return 1;
}

int main() {
    fastio;

    ll t;
    cin >> t;

    while (t--) {
        ll v, e;
        cin >> v >> e;

        for (int i = 0; i < e; i++) {
            ll a, b;
            cin >> a >> b;
            vertex[a].push_back(b);
            vertex[b].push_back(a);
        }

        ll check = 0;
        for (int i = 1; i <= v; i++) {
            if (visited[i] == 0) {
                check = bfs(i);
                if (!check) break;
            }
        }

        if (check) cout << "YES" << endl;
        else cout << "NO" << endl;

        for (int i = 1; i <= v; i++) vertex[i].clear();
        memset(visited, 0, sizeof(visited));
    }

    return 0;
}