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

ll dp[100005][2];

int main() {
    fastio;

    ll n;
    cin >> n;

    dp[0][0] = 1;
    dp[0][1] = 2;
    for (int i = 1; i < n; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
        dp[i][1] = (dp[i - 1][0] * 2 + dp[i - 1][1]) % 9901;
    }

    cout << (dp[n - 1][0] + dp[n - 1][1]) % 9901;

    return 0;
}