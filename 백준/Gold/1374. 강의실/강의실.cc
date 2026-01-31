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

    ll n;
    cin >> n;

    vector<pll> v(n);
    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        v[i] = {b, c};
    }

    sort(v.begin(), v.end());

    priority_queue<ll, vector<ll>, greater<>> pq;
    ll res = 1;
    pq.push(v[0].second);

    for (int i = 1; i < n; i++) {
        while (!pq.empty() && pq.top() <= v[i].first) {
            pq.pop();
        }
        pq.push(v[i].second);

        res = max(res, (ll)pq.size());
    }

    cout << res;

    return 0;
}