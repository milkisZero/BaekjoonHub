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

    string s;
    map<string, ll> mp;
    double cnt = 0;
    while (getline(cin, s)) {
        mp[s]++;
        cnt++;
    }

    cout << fixed;
    cout.precision(4);

    for (auto [k, v] : mp) {
        double d = (v / cnt * 100);
        cout << k << sp << d << endl;
    }

    return 0;
}