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

vector<ll> v[1005];
ll dp[1005][1005][3];

int main() {
    fastio;

    ll n, m;
    cin >> n >> m;

    v[0].resize(m);
    for (int i = 1; i <= n; i++) {
        v[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    fill(&dp[1][0][0], &dp[1004][1004][2], INF);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {

            for (int k = 0; k < 3; k++) {
                if (k != 0 && j + 1 < m)
                    dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j + 1][k] + v[i][j]);

                if (k != 1)
                    dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][k] + v[i][j]);

                if (k != 2 && j - 1 >= 0)
                    dp[i][j][2] = min(dp[i][j][2], dp[i - 1][j - 1][k] + v[i][j]);
            }
        }
    }

    ll res = LLINF;
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < 3; k++) {
            res = min(res, dp[n][j][k]);
        }
    }

    cout << res;

    return 0;
}