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

void recur(ll r1, ll r2, ll c1, ll c2, ll n) {

    n /= 2;

    cout << "(";

    bool w = 0, b = 0;
    for (int i = r1; i < r1 + n; i++) {
        for (int j = c1; j < c1 + n; j++) {
            if (v[i][j] == '1') w = 1;
            else b = 1;
        }
    }
    if (w && b == 0) cout << '1';
    else if (w == 0 && b) cout << '0';
    else recur(r1, r1 + n, c1, c1 + n, n);

    w = 0, b = 0;
    for (int i = r1; i < r1 + n; i++) {
        for (int j = c1 + n; j < c1 + 2 * n; j++) {
            if (v[i][j] == '1') w = 1;
            else b = 1;
        }
    }
    if (w && b == 0) cout << '1';
    else if (w == 0 && b) cout << '0';
    else recur(r1, r1 + n, c1 + n, c1 + 2 * n, n);

    w = 0, b = 0;
    for (int i = r1 + n; i < r1 + 2 * n; i++) {
        for (int j = c1; j < c1 + n; j++) {
            if (v[i][j] == '1') w = 1;
            else b = 1;
        }
    }
    if (w && b == 0) cout << '1';
    else if (w == 0 && b) cout << '0';
    else recur(r1 + n, r1 + 2 * n, c1, c1 + n, n);

    w = 0, b = 0;
    for (int i = r1 + n; i < r1 + 2 * n; i++) {
        for (int j = c1 + n; j < c1 + 2 * n; j++) {
            if (v[i][j] == '1') w = 1;
            else b = 1;
        }
    }
    if (w && b == 0) cout << '1';
    else if (w == 0 && b) cout << '0';
    else recur(r1 + n, r1 + 2 * n, c1 + n, c1 + 2 * n, n);

    cout << ")";

    return;
}

int main() {
    fastio;

    ll n;
    cin >> n;

    v.resize(n);
    for (auto &e : v) {
        cin >> e;
    }

    bool w = 0, b = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == '1') w = 1;
            else b = 1;
        }
    }
    if (w && b == 0) cout << '1';
    else if (w == 0 && b) cout << '0';
    else recur(0, n, 0, n, n);

    return 0;
}