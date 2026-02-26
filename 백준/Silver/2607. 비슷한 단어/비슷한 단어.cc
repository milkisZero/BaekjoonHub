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

map<char, ll> mp;

int main() {
    fastio;

    ll n;
    cin >> n;

    string s;
    cin >> s;

    for (int j = 0; j < s.size(); j++) mp[s[j]]++;

    ll cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        string a;
        cin >> a;

        map<char, ll> tmp;
        for (int j = 0; j < a.size(); j++) tmp[a[j]]++;

        ll c = 0, d = 0;
        ll check = 0;
        for (char j = 'A'; j <= 'Z'; j++) {
            ll k = mp[j] - tmp[j];

            if (k == 0) continue;

            if (k < 0) {
                if (c) {
                    check = 1;
                    break;
                }
                c += -k;
            }
            else {
                if (d) {
                    check = 1;
                    break;
                }
                d += k;
            }
        }

        if (check) continue;
        if ((c == d && d == 1) || (c == d && d == 0) || c + d == 1) cnt++;
    }

    cout << cnt;

    return 0;
}