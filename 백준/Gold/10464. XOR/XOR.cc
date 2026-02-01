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

ll calc(ll k) {
    ll res = 0;
    for (int i = (k / 4) * 4; i <= k; i++) {
        res ^= i;
    }

    return res;
}

int main() {
    fastio;

    ll t;
    cin >> t;

    while (t--) {
        ll a, b;
        cin >> a >> b;
        cout << (calc(b) ^ calc(a - 1)) << endl;
    }

    return 0;
}