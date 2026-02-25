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

    ll n, m;
    cin >> n >> m;

    vector<ll> v(m);
    for (int i = 0; i < m; i++) cin >> v[i];

    if (n <= m) {
        cout << n;
        return 0;
    }

    ll l = 0, r = 30 * n, mid;
    ll res = 0, time = 0;
    while (l <= r) {
        mid = (l + r) / 2;

        ll cnt = 0;
        for (int i = 0; i < m; i++) cnt += (mid / v[i]) + 1;

        if (cnt >= n) r = mid - 1;
        else {
            res = cnt;
            time = mid;
            l = mid + 1;
        }
    }

    n -= res;
    time++;
    for (int i = 0; i < m; i++) {
        if (time % v[i] == 0) {
            n--;
            if (n == 0) {
                cout << i + 1;
                return 0;
            }
        }
    }

    return 0;
}