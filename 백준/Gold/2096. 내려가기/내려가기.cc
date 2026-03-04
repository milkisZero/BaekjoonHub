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

ll dp[3];
ll dp2[3];

int main() {
    fastio;

    ll n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        vector<ll> v(3);
        for (int j = 0; j < 3; j++) {
            cin >> v[j];
        }

        if (i == 0) {
            dp[0] = dp2[0] = v[0];
            dp[1] = dp2[1] = v[1];
            dp[2] = dp2[2] = v[2];
            continue;
        }

        ll k1 = v[0] + max(dp[0], dp[1]);
        ll k2 = v[1] + max(dp[0], max(dp[1], dp[2]));
        ll k3 = v[2] + max(dp[1], dp[2]);

        ll k4 = v[0] + min(dp2[0], dp2[1]);
        ll k5 = v[1] + min(dp2[0], min(dp2[1], dp2[2]));
        ll k6 = v[2] + min(dp2[1], dp2[2]);

        dp[0] = k1;
        dp[1] = k2;
        dp[2] = k3;

        dp2[0] = k4;
        dp2[1] = k5;
        dp2[2] = k6;
    }

    cout << max(dp[0], max(dp[1], dp[2])) << sp;
    cout << min(dp2[0], min(dp2[1], dp2[2]));

    return 0;
}