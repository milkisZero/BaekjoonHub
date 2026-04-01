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

int dp[26][10];

int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    int maxi = 1;

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;

        int pre_maxi = 0;
        for (int j = 0; j < k; j++) {
            int idx = tmp[j] - 'a';
            pre_maxi = max(pre_maxi, dp[idx][j]);
        }

        for (int j = 0; j < k; j++) {
            int idx = tmp[j] - 'a';
            dp[idx][j] = pre_maxi + 1;
        }
        maxi = max(maxi, pre_maxi + 1);
    }

    cout << n - maxi;

    return 0;
}