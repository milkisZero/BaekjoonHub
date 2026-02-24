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

ll dp[300005];

int main() {
    fastio;

    ll n, s;
    cin >> n >> s;

    vector<pll> v(n + 1);
    v[0] = {0, 0};
    for (int i = 1; i <= n; i++) cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());

    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i], dp[i - 1]);

        ll idx = lower_bound(v.begin(), v.begin() + i, pll(v[i].first - s + 1, 0)) - v.begin();

        dp[i] = max(dp[i], dp[idx - 1] + v[i].second);
    }

    cout << dp[n];

    return 0;
}