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

ll dp[2505];

int main() {
    fastio;

    string s;
    cin >> s;

    fill(&dp[0], &dp[2505], LLINF);

    dp[0] = 1;
    for (int i = 1; i < s.size(); i++) {
        string tmp = "";
        string tmp2 = "";

        for (int j = i; j >= 0; j--) {
            tmp += s[j];
            tmp2 = s[j] + tmp2;

            if (s[j] == s[i]) {
                if (tmp == tmp2) {
                    if (j == 0) dp[i] = 1;
                    else dp[i] = min(dp[j - 1] + 1, dp[i]);
                }
            }
        }
    }

    cout << dp[s.size() - 1];

    return 0;
}