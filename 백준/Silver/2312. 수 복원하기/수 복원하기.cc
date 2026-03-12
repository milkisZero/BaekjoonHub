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

int main() {
    fastio;

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        ll k = n;
        for (int i = 2; i <= k && n; i++) {
            ll cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }

            if (cnt) cout << i << sp << cnt << endl;
        }
    }

    return 0;
}