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

bool isPal[2505][2505];
ll dp[2505];

int main() {
    fastio;

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) isPal[i][i] = 1;

    for (int len = 2; len <= s.size(); len++) {
        for (int i = 0; i + len - 1 < s.size(); i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                if (len == 2) isPal[i][j] = 1;
                else isPal[i][j] = isPal[i + 1][j - 1];
            }
        }
    }

    fill(&dp[0], &dp[2505], LLINF);

    dp[0] = 1;
    for (int i = 1; i < s.size(); i++) {
        for (int j = i; j >= 0; j--) {
            if (isPal[j][i]) {
                if (j == 0) dp[i] = 1;
                else dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }

    cout << dp[s.size() - 1];

    return 0;
}