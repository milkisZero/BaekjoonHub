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

string a, b;

int main() {
    fastio;

    cin >> a >> b;

    ll mini = LLINF;
    for (int i = 0; i < b.size(); i++) {
        ll cnt = 0;
        if (i + a.size() > b.size()) break;
        for (int j = 0; j < a.size(); j++) {
            if (b[i + j] != a[j]) cnt++;
        }
        mini = min(mini, cnt);
    }

    if (mini == LLINF) mini = 0;
    cout << mini;

    return 0;
}