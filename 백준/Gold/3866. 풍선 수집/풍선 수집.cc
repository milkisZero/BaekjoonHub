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

// i = 풍선 번호
// j = 현재 차량의 풍선 개수
// val = 최소 이동 거리
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

        ll idx = 0;
        // 1 칸 이동하는데 k+1 시간
        for (int i = 0; i < n; i++) {
            idx = i;
            if (i == 0) {
                if (v[0].first <= v[0].second) {
                    dp[0][1] = v[0].first;
                    continue;
                }
                else break;
            }

            ll time = v[i - 1].second;
            bool k = 0;

            for (int j = 0; j <= 3; j++) {
                bool ini = dp[i - 1][j] == LLINF;

                // 집에 들려서 차량 비우고 담기 - 시간 체크
                if (!ini && v[i].second >= time + v[i - 1].first * (j + 1) + v[i].first) {
                    dp[i][1] = min(dp[i][1], dp[i - 1][j] + v[i - 1].first + v[i].first);
                    k = 1;
                }

                // 집에 안들리고 바로 담기
                if (j < 3 && !ini && v[i].second >= time + abs(v[i - 1].first - v[i].first) * (j + 1)) {
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j] + abs(v[i - 1].first - v[i].first));
                    k = 1;
                }
            }
            if (!k) break;
        }

        ll mini = LLINF;
        for (int j = 0; j <= 3; j++) {
            mini = min(mini, dp[n - 1][j]);
        }

        if (mini == LLINF) {
            cout << "NG " << idx + 1 << endl;
        }
        else {
            ll res = mini + v[n - 1].first;
            cout << "OK " << res << endl;
        }
    }

    return 0;
}