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

    bool check = 0;

    vector<ll> p(n), s(n), v(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        v[i] = i;

        if ((i % 3) != p[v[i]]) check = 1;
    }

    if (!check) {
        cout << 0;
        return 0;
    }

    vector<ll> v2(n);
    ll cnt = 0;
    while (1) {
        cnt++;
        for (int i = 0; i < n; i++) v2[s[i]] = v[i];
        swap(v, v2);

        ll tmp = 0;
        check = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == i) tmp++;
            if ((i % 3) != p[v[i]]) check = 1;
        }

        if (tmp == n) {
            cout << -1;
            return 0;
        }
        else if (!check) break;
    }

    cout << cnt;

    return 0;
}