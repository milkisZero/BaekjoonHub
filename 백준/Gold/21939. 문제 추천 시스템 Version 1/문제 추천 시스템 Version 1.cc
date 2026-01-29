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

set<pll> st;
map<ll, ll> mp;

int main() {
    fastio;

    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        st.insert({b, a});
        mp[a] = b;
    }

    ll k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;

        if (s == "add") {
            ll a, b;
            cin >> a >> b;
            mp[a] = b;
            st.insert({b, a});
        }
        else if (s == "recommend") {
            ll a;
            cin >> a;
            if (a == 1) cout << (*st.rbegin()).second << endl;
            else cout << (*st.begin()).second << endl;
        }
        else {
            ll a;
            cin >> a;
            st.erase({mp[a], a});
            mp.erase(a);
        }
    }

    return 0;
}