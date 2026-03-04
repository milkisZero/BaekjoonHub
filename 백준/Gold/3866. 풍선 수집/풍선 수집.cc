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

ll dp[44][4];

int main() {
    fastio;

    while (1) {
        ll n;
        cin >> n;
        if (!n) break;

        vector<pll> v(n);
        for (auto &[a, b] : v) cin >> a >> b;

        fill(&dp[0][0], &dp[43][3], LLINF);

        int i = 0;
        for (i = 0; i < n; i++) {
            if (i == 0) {
                if (v[0].first <= v[0].second) {
                    dp[0][1] = v[0].first;
                    continue;
                }
                break;
            }

            ll time = v[i - 1].second;
            bool k = 0;
            for (int j = 0; j <= 3; j++) {
                if (dp[i - 1][j] == LLINF) continue;

                if (v[i].second >= time + v[i - 1].first * (j + 1) + v[i].first) {
                    dp[i][1] = min(dp[i][1], dp[i - 1][j] + v[i - 1].first + v[i].first);
                    k = 1;
                }

                if (j < 3 && v[i].second >= time + abs(v[i - 1].first - v[i].first) * (j + 1)) {
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j] + abs(v[i - 1].first - v[i].first));
                    k = 1;
                }
            }
            if (!k) break;
        }

        ll mini = LLINF;
        for (int j = 0; j <= 3; j++) mini = min(mini, dp[n - 1][j]);

        if (mini == LLINF) cout << "NG " << i + 1 << endl;
        else cout << "OK " << mini + v[n - 1].first << endl;
    }

    return 0;
}