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

    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    deque<ll> dq;
    for (int i = 0; i < n; i++) dq.push_back(v[i]);

    ll res = 0;
    deque<ll> dq2;
    dq2.push_back(dq.back());
    dq.pop_back();

    while (!dq.empty()) {
        ll l1 = abs(dq2.front() - dq.front());
        ll l2 = abs(dq2.front() - dq.back());
        ll r1 = abs(dq2.back() - dq.front());
        ll r2 = abs(dq2.back() - dq.back());

        ll maxi = max({l1, l2, r1, r2});
        res += maxi;
        if (maxi == l1) {
            dq2.push_front(dq.front());
            dq.pop_front();
        }
        else if (maxi == l2) {
            dq2.push_front(dq.back());
            dq.pop_back();
        }
        else if (maxi == r1) {
            dq2.push_back(dq.front());
            dq.pop_front();
        }
        else {
            dq2.push_back(dq.back());
            dq.pop_back();
        }
    }

    cout << res;

    return 0;
}