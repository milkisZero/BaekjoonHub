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
#define MOD 1000000009

ll dp[100000][4];

int main() {
    fastio;

    ll n;
    cin >> n;

    vector<ll> v(n);
    for (auto &e : v) cin >> e;

    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for (int i = 4; i <= 100000; i++) {
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
                if (j != k) {
                    dp[i][j] = (dp[i][j] + dp[i - j][k]) % MOD;
                }
            }
        }
    }

    for (auto &e : v) {
        cout << (dp[e][1] + dp[e][2] + dp[e][3]) % MOD << endl;
    }

    return 0;
}