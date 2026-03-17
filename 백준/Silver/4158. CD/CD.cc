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

    ll n, m;
    while (cin >> n >> m) {
        if (!n && !m) break;

        unordered_set<ll> st;
        for (int i = 0; i < n; i++) {
            ll tmp;
            cin >> tmp;
            st.insert(tmp);
        }

        ll cnt = 0;
        for (int i = 0; i < m; i++) {
            ll tmp;
            cin >> tmp;

            if (st.find(tmp) != st.end()) cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}