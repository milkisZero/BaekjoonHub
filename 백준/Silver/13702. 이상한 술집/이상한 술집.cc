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

ll n, k;

ll func(ll m, vector<ll> v) {
    ll cnt = 0;
    for (auto e : v) {
        cnt += e / m;
        if (cnt >= k) break;
    }

    if (cnt >= k) return 1;
    return 0;
}

int main() {
    fastio;

    cin >> n >> k;

    vector<ll> v(n);
    ll maxi = -1;
    for (auto &e : v) {
        cin >> e;
        maxi = max(maxi, e);
    }

    ll l = 1, r = maxi, m;
    ll res = 0;
    while (l <= r) {
        m = (l + r) / 2;

        if (func(m, v)) {
            l = m + 1;
            res = m;
        }
        else r = m - 1;
    }

    cout << res;

    return 0;
}