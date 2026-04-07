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

    int n;
    cin >> n;

    unordered_map<ll, pll> mp;
    mp[0] = {-1, -1};

    for (int i = 1; i <= n; i++) {
        char q;
        cin >> q;
        if (q == 's') mp[i] = mp[mp[i - 1].second];
        else {
            int k;
            cin >> k;

            if (q == 'a') mp[i] = {k, i - 1};
            else mp[i] = mp[k - 1];
        }

        cout << mp[i].first << endl;
    }

    return 0;
}