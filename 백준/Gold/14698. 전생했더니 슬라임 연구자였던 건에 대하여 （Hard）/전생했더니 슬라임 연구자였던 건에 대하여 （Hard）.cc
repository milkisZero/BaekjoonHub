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
#define MOD 1000000007

int main() {
    fastio;

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int i = 0; i < n; i++) {
            ll tmp;
            cin >> tmp;
            pq.push(tmp);
        }

        ll cnt = 1;
        while (pq.size() != 1) {
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();

            cnt *= (a * b) % MOD;
            cnt %= MOD;

            pq.push(a * b);
        }

        cout << cnt << endl;
    }

    return 0;
}