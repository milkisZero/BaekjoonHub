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

    vector<ll> psum[205];
    for (int i = 1; i <= n; i++) {
        psum[i].resize(205, 0);
        for (int j = 1; j <= m; j++) {
            ll val;
            cin >> val;
            psum[i][j] = psum[i][j - 1] + val;
        }
    }

    ll res = -LLINF;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {

            for (int k = j + 1; k <= m; k++) {
                ll sum = psum[i][k] - psum[i][j];
                res = max(res, sum);

                for (int p = i + 1; p <= n; p++) {
                    sum += psum[p][k] - psum[p][j];
                    res = max(res, sum);
                }
            }
        }
    }

    cout << res;

    return 0;
}