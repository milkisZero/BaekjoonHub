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

ll maxi;

void func(ll cur, vector<ll> v, ll val) {
    v.erase(v.begin() + cur);

    if (v.size() == 2) {
        maxi = max(maxi, val);
        return;
    }

    for (int i = 1; i < v.size() - 1; i++) func(i, v, val + v[i - 1] * v[i + 1]);
}

int main() {
    fastio;

    ll n;
    cin >> n;

    vector<ll> v(n);
    for (auto &e : v) cin >> e;

    for (int i = 1; i < n - 1; i++) func(i, v, v[i - 1] * v[i + 1]);

    cout << maxi;

    return 0;
}