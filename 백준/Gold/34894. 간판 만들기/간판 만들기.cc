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

ll dp[300005][5];
char str[5] = {'U', 'O', 'S', 'P', 'C'};

int main() {
    fastio;

    ll n;
    cin >> n;

    fill(&dp[0][0], &dp[n][5], LLINF / 2);

    string s;
    cin >> s;

    ll val, idx;
    cin >> val;

    for (int j = 0; j <= 4; j++)
        if (s[0] == str[j]) idx = j;

    if (s[0] == 'U') dp[0][idx] = val;

    for (int i = 1; i < n; i++) {
        cin >> val;

        if (s[i] == 'U') dp[i][0] = min(dp[i - 1][0], val);
        else dp[i][0] = dp[i - 1][0];

        for (int j = 1; j <= 4; j++) {
            if (s[i] == str[j]) dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + val);
            else dp[i][j] = dp[i - 1][j];
        }
    }

    if (dp[n - 1][4] == LLINF / 2) cout << -1;
    else cout << dp[n - 1][4];

    return 0;
}