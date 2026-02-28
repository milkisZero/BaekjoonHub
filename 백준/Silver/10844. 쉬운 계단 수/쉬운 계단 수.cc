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

ll dp[102][11];

int main() {
    fastio;

    ll n;
    cin >> n;
    const ll mod = 1000000000;

    for (int i = 1; i <= 9; i++) dp[0][i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j - 1 >= 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
            if (j + 1 < 10)
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
        }
    }

    ll sum = 0;
    for (int i = 0; i <= 9; i++) {
        sum += dp[n - 1][i];
        sum %= mod;
    }
    cout << sum;

    return 0;
}