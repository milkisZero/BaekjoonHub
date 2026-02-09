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

map<ll, pll> mp;

int main() {
    fastio;

    ll n, c;
    cin >> n >> c;

    vector<ll> v(n);
    for (int i = n - 1; i >= 0; i--) {
        cin >> v[i];

        if (mp.find(v[i]) == mp.end()) mp[v[i]] = {i, 1};
        else mp[v[i]].second++;
    }

    sort(v.begin(), v.end(), [](ll a, ll b) {
        if (mp[a].second == mp[b].second) {
            return mp[a].first > mp[b].first;
        }
        return mp[a].second > mp[b].second;
    });

    for (auto e : v) cout << e << sp;

    return 0;
}