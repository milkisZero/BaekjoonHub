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

ll par[4000006];

void init(ll n) {
    for (int i = 1; i < n; i++) par[i] = i;
}

ll find(ll a) {
    if (a == par[a]) return a;
    return par[a] = find(par[a]);
}

void uni(ll a, ll b) {
    if (find(a) != find(b))
        par[find(a)] = find(b);
}

int main() {
    fastio;

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> v(m);
    for (int i = 0; i < m; i++) cin >> v[i];
    sort(v.begin(), v.end());

    init(m);

    for (int i = 0; i < k; i++) {
        ll tmp;
        cin >> tmp;

        ll idx = upper_bound(v.begin(), v.end(), tmp) - v.begin();
        ll f_idx = find(idx);
        cout << v[f_idx] << endl;
        uni(f_idx, f_idx + 1);
    }

    return 0;
}