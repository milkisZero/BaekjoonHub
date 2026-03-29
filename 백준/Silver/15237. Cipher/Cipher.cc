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

unordered_map<ll, ll> freq;
map<ll, ll> idx;

int main() {
    fastio;

    ll n, m;
    cin >> n >> m;

    vector<ll> v;
    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        v.push_back(tmp);

        freq[tmp]++;
        if (idx.find(tmp) == idx.end()) idx[tmp] = i;
    }

    sort(v.begin(), v.end(), [](ll a, ll b) {
        if (freq[a] == freq[b]) return idx[a] < idx[b];
        return freq[a] > freq[b];
    });

    for (auto e : v) cout << e << sp;

    return 0;
}