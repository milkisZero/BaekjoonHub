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

    vector<ll> v(n), v2(n);
    for (auto &e : v) cin >> e;

    vector<ll> lis(n);
    ll head = 0;
    lis[0] = v[0];
    for (int i = 0; i < n; i++) {
        if (lis[head] >= v[i]) {
            ll idx = lower_bound(lis.begin(), lis.begin() + head, v[i]) - lis.begin();
            lis[idx] = v[i];
            v2[i] = idx;
        }
        else {
            lis[++head] = v[i];
            v2[i] = head;
        }
    }

    ll tmp = head;
    for (int i = n - 1; i >= 0; i--) {
        if (v2[i] == tmp) {
            lis[tmp] = v[i];
            tmp--;
        }
    }

    cout << head + 1 << endl;
    for (int i = 0; i <= head; i++) cout << lis[i] << sp;

    return 0;
}