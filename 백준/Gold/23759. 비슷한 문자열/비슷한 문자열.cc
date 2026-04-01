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

int dp[500005];
int mp[26][10];

int main() {
    fastio;

    ll n, k;
    cin >> n >> k;

    memset(mp, -1, sizeof(mp));

    vector<string> v(n);
    int maxi = 1;

    for (int i = 0; i < n; i++) {
        cin >> v[i];

        dp[i] = 1;
        for (int j = 0; j < k; j++) {
            ll idx = v[i][j] - 'a';
            if (mp[idx][j] != -1) {
                int pre = mp[idx][j];
                dp[i] = max(dp[i], dp[pre] + 1);
                maxi = max(maxi, dp[i]);
            }

            mp[idx][j] = i;
        }
    }

    cout << n - maxi;

    return 0;
}