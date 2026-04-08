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

    ll n;
    cin >> n;

    vector<ll> p(n), s(n), v(n), v2(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        v2[i] = v[i] = i;
    }

    bool check = 0;
    for (int i = 0; i < n; i++) {
        ll k = (i % 3);
        if (k != p[v2[i]]) {
            check = 1;
        }
    }

    if (!check) {
        cout << 0;
        return 0;
    }

    ll cnt = 0;
    while (1) {
        cnt++;
        vector<ll> v3(n);
        for (int i = 0; i < n; i++) {
            v3[s[i]] = v2[i];
        }
        v2 = v3;

        if (v2 == v) {
            cout << -1;
            return 0;
        }

        bool check = 0;
        for (int i = 0; i < n; i++) {
            ll k = (i % 3);
            if (k != p[v2[i]]) {
                check = 1;
            }
        }

        if (!check) break;
    }

    cout << cnt;

    return 0;
}