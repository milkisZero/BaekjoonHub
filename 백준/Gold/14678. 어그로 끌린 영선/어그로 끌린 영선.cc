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

vector<ll> g[1000006];
ll visited[1000006];
pll root_res;

void dfs(ll cur, ll cnt) {
    visited[cur] = 1;

    ll end = 1;
    for (auto e : g[cur]) {
        if (!visited[e]) {
            end = 0;
            dfs(e, cnt + 1);
        }
    }

    if (end) {
        if (cnt % 2) root_res.first++;
        else root_res.second++;
    }
    return;
}

int main() {
    fastio;

    ll n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ll all_leaf = 0;
    ll s = 1;
    for (int i = 1; i <= n; i++) {
        if (n > 1 && g[i].size() == n - 1) all_leaf = 1;

        if (g[i].size() > 1) s = i;
    }

    dfs(s, 1);

    cout << max(root_res.first, root_res.second) - all_leaf;

    return 0;
}