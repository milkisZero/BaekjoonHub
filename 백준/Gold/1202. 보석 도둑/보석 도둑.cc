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

    ll n, k;
    cin >> n >> k;

    vector<pll> v(n);
    for (auto &[a, b] : v) {
        ll tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        a = -tmp2, b = tmp1;
    }
    sort(v.begin(), v.end());

    multiset<ll> ms;
    for (int i = 0; i < k; i++) {
        ll tmp;
        cin >> tmp;
        ms.insert(tmp);
    }

    ll sum = 0;
    for (auto [a, b] : v) {
        auto iter = ms.lower_bound(b);
        if (iter == ms.end()) continue;

        sum += -a;
        ms.erase(iter);

        if (ms.size() == 0) break;
    }

    cout << sum;

    return 0;
}