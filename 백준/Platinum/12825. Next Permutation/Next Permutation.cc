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

    set<ll> st;
    st.insert(v[n - 1]);
    ll idx = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (st.upper_bound(v[i]) != st.end()) {
            idx = i;
            st.insert(v[i]);
            ll tmp = *st.upper_bound(v[i]);
            v[i] = tmp;
            st.erase(tmp);
            break;
        }

        st.insert(v[i]);
    }

    ll l = idx + 1;
    ll r = n - 1;
    for (auto iter = st.rbegin(); iter != st.rend(); iter++) {
        if (v[idx] > *iter) {
            v[l] = *iter;
            l++;
        }
        else {
            v[r] = *iter;
            r--;
        }
    }

    for (auto &e : v) cout << e << sp;

    return 0;
}