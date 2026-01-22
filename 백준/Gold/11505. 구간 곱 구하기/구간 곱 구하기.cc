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
#define MAX 1000006
#define MOD 1000000007

ll seg[(MAX + 5) * 4], arr[MAX + 5];

ll init(ll n, ll l, ll r) {
    if (l == r) return seg[n] = arr[l];
    return seg[n] = (init(2 * n, l, (l + r) / 2) * init(2 * n + 1, (l + r) / 2 + 1, r)) % MOD;
}

ll upd(ll n, ll l, ll r, ll t, ll v) {
    if (t < l || r < t) return seg[n];
    if (l == r) return seg[n] = v % MOD;
    return seg[n] = (upd(2 * n, l, (l + r) / 2, t, v) * upd(2 * n + 1, (l + r) / 2 + 1, r, t, v)) % MOD;
}

ll qry(ll n, ll l, ll r, ll ql, ll qr) {
    if (qr < l || r < ql) return 1;
    if (ql <= l && r <= qr) return seg[n];
    return (qry(2 * n, l, (l + r) / 2, ql, qr) * qry(2 * n + 1, (l + r) / 2 + 1, r, ql, qr)) % MOD;
}

int main() {
    fastio;

    ll n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) cin >> arr[i];
    init(1, 1, n);

    for (int i = 0; i < m + k; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 1) upd(1, 1, n, b, c);
        else cout << qry(1, 1, n, b, c) << endl;
    }

    return 0;
}
