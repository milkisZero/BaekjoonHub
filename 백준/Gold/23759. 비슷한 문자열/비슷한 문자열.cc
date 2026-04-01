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
    int maxi = 1;

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;

        dp[i] = 1;
        for (int j = 0; j < k; j++) {
            int idx = tmp[j] - 'a';
            if (mp[idx][j] != -1) {
                dp[i] = max(dp[i], dp[mp[idx][j]] + 1);
                maxi = max(maxi, dp[i]);
            }
            mp[idx][j] = i;
        }
    }

    cout << n - maxi;

    return 0;
}