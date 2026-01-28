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

        multiset<ll> ms;
        for (int i = 0; i < n; i++) {
            char c;
            ll k;
            cin >> c >> k;

            if (c == 'I') ms.insert(k);
            else {
                if (ms.empty()) continue;
                if (k == -1) ms.erase(ms.begin());
                else ms.erase(prev(ms.end()));
            }
        }

        if (ms.empty()) cout << "EMPTY" << endl;
        else cout << *ms.rbegin() << sp << *ms.begin() << endl;
    }

    return 0;
}