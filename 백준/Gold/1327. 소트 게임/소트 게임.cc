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

ll n, k;
map<vector<ll>, ll> mp;
vector<ll> sorty;

void bfs(vector<ll> v) {
    mp[v] = 0;

    queue<vector<ll>> q;
    q.push(v);

    while (!q.empty()) {
        vector<ll> v2 = q.front();
        q.pop();

        for (int i = v2.size() - k; i >= 0; i--) {
            vector<ll> tmp(n);

            for (int j = 0; j < i; j++) tmp[j] = v2[j];

            for (int j = 0; j < k; j++) tmp[i + j] = v2[i + k - 1 - j];

            for (int j = i + k; j < v2.size(); j++) tmp[j] = v2[j];

            if (mp.find(tmp) == mp.end()) {
                mp[tmp] = mp[v2] + 1;

                if (tmp != sorty) q.push(tmp);
            }
            else mp[tmp] = min(mp[tmp], mp[v2] + 1);
        }
    }

    return;
}

int main() {
    fastio;

    cin >> n >> k;

    vector<ll> v(n);
    sorty.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sorty[i] = v[i];
    }
    sort(sorty.begin(), sorty.end());

    bfs(v);

    if (mp.find(sorty) == mp.end()) cout << -1;
    else cout << mp[sorty];

    return 0;
}