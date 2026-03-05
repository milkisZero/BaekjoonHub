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

ll dp[1000005];

int main() {
    fastio;

    ll n;
    cin >> n;

    ll maxi = 0;
    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        dp[tmp] = dp[tmp - 1] + 1;
        maxi = max(maxi, dp[tmp]);
    }

    cout << n - maxi;

    return 0;
}