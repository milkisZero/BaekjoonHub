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
    for (auto &[a, b] : v) cin >> a >> b;
    sort(v.begin(), v.end());

    priority_queue<ll, vector<ll>, greater<>> pq;
    pq.push(v[0].second);

    for (int i = 1; i < n; i++) {
        if (pq.size() == v[i].first) {
            if (pq.top() < v[i].second) {
                pq.pop();
                pq.push(v[i].second);
            }
        }
        else pq.push(v[i].second);
    }

    ll sum = 0;
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }

    cout << sum;

    return 0;
}