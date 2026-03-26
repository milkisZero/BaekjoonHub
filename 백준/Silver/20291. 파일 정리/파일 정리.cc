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

    map<string, int> mp;

    string s;
    while (n--) {
        cin >> s;
        istringstream iss(s);

        string buf;
        int idx = 0;
        while (getline(iss, buf, '.')) {
            if (idx == 1) mp[buf]++;
            idx++;
        }
    }

    for (auto [k, v] : mp) cout << k << sp << v << endl;

    return 0;
}