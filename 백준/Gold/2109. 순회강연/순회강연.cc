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
    for (auto &[a, b] : v) cin >> b >> a;

    sort(v.begin(), v.end());

    priority_queue<ll, vector<ll>, greater<>> pq;
    for (auto [a, b] : v) {
        if (pq.size() < a) pq.push(b);
        else {
            pq.push(b);
            pq.pop();
        }
    }

    ll cnt = 0;
    while (!pq.empty()) {
        cnt += pq.top();
        pq.pop();
    }
    cout << cnt;

    return 0;
}