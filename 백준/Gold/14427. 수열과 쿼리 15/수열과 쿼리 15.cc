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

ll seg[(MAX + 5) * 4], arr[MAX + 5];

ll init(ll n, ll l, ll r) {
    if (l == r) return seg[n] = l;
    ll l_idx = init(2 * n, l, (l + r) / 2);
    ll r_idx = init(2 * n + 1, (l + r) / 2 + 1, r);

    if (arr[l_idx] <= arr[r_idx]) return seg[n] = l_idx;
    return seg[n] = r_idx;
}

ll upd(ll n, ll l, ll r, ll t, ll v) {
    if (t < l || r < t) return seg[n];
    if (l == r) {
        arr[t] = v;
        return seg[n];
    }
    ll l_idx = upd(2 * n, l, (l + r) / 2, t, v);
    ll r_idx = upd(2 * n + 1, (l + r) / 2 + 1, r, t, v);

    if (arr[l_idx] <= arr[r_idx]) return seg[n] = l_idx;
    return seg[n] = r_idx;
}

int main() {
    fastio;

    ll n, m;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> arr[i];
    init(1, 1, n);
    arr[0] = LLINF;

    cin >> m;
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a;

        if (a == 1) {
            cin >> b >> c;
            upd(1, 1, n, b, c);
        }
        else cout << seg[1] << endl;
    }

    return 0;
}
