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

ll d[100005];
vector<pll> e[100005];

int main() {
    fastio;

    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        e[a].push_back({b, i});
        e[b].push_back({a, i});
    }

    fill(&d[2], &d[100003], LLINF);

    priority_queue<pll> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [val, node] = pq.top();
        pq.pop();
        val = -val;

        if (d[node] == val) {
            for (auto [next, i] : e[node]) {

                ll k = val / m * m + i;
                if (k < val) k += m;
                k++;

                if (d[next] > k) {
                    d[next] = k;
                    pq.push({-k, next});
                }
            }
        }
    }

    cout << d[n];

    return 0;
}