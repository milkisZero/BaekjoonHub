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
    for (auto &e : v) cin >> e;

    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll head = 0;
        ll head2 = 0;

        vector<ll> lis(n);
        vector<ll> lds(n);
        lis[0] = v[i];
        lds[0] = v[i];

        for (int j = i + 1; j < n; j++) {
            if (lis[head] >= v[j]) {
                ll idx = lower_bound(lis.begin(), lis.begin() + head + 1, v[j]) - lis.begin();
                if (idx)
                    lis[idx] = v[j];
            }
            else lis[++head] = v[j];

            if (lds[head2] <= v[j]) {
                ll idx = lower_bound(lds.begin(), lds.begin() + head2 + 1, v[j], greater<>()) - lds.begin();
                if (idx)
                    lds[idx] = v[j];
            }
            else lds[++head2] = v[j];
        }

        res = max(res, head + head2 + 1);
    }

    cout << res;

    return 0;
}