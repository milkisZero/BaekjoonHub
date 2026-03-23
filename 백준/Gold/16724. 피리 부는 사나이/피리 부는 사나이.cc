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

string s[1003];
bool visited[1003][1003];
ll par[1000006];
ll n, m;

void init(int n) {
    for (int i = 0; i < n; i++) par[i] = i;
}

ll find(ll a) {
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}

void uni(ll a, ll b) {
    if (a < b) swap(a, b);
    par[find(a)] = find(b);
}

map<char, pll> mp = {
    {'D', {1, 0}},
    {'U', {-1, 0}},
    {'R', {0, 1}},
    {'L', {0, -1}}};

void dfs(ll a, ll b) {
    visited[a][b] = 1;

    auto dir = mp[s[a][b]];

    uni(a * m + b, (a + dir.first) * m + b + dir.second);

    if (!visited[a + dir.first][b + dir.second]) dfs(a + dir.first, b + dir.second);
}

int main() {
    fastio;

    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> s[i];

    init(n * m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == 0) {
                dfs(i, j);
            }
        }
    }

    ll cnt = 0;
    for (int i = 0; i < n * m; i++) {
        if (par[i] == i) cnt++;
    }
    cout << cnt;

    return 0;
}