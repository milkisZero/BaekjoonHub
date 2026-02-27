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

vector<string> v;

bool check(ll r1, ll r2, ll c1, ll c2) {
    bool w = 0, b = 0;
    for (int i = r1; i < r2; i++) {
        for (int j = c1; j < c2; j++) {
            if (v[i][j] == '1') w = 1;
            else b = 1;
        }
    }

    if (w + b == 1) {
        if (w) cout << '1';
        else cout << '0';
        return 0;
    }

    return 1;
}

void recur(ll r1, ll c1, ll n) {

    n /= 2;

    cout << "(";

    if (check(r1, r1 + n, c1, c1 + n)) recur(r1, c1, n);

    if (check(r1, r1 + n, c1 + n, c1 + n * 2)) recur(r1, c1 + n, n);

    if (check(r1 + n, r1 + 2 * n, c1, c1 + n)) recur(r1 + n, c1, n);

    if (check(r1 + n, r1 + 2 * n, c1 + n, c1 + 2 * n)) recur(r1 + n, c1 + n, n);

    cout << ")";

    return;
}

int main() {
    fastio;

    ll n;
    cin >> n;

    v.resize(n);
    for (auto &e : v) cin >> e;

    if (check(0, n, 0, n)) recur(0, 0, n);

    return 0;
}