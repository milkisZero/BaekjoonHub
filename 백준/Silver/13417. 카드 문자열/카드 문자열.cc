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

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        deque<char> dq;
        char c;
        cin >> c;
        dq.push_back(c);

        for (int i = 1; i < n; i++) {
            cin >> c;
            if (dq.front() >= c) dq.push_front(c);
            else dq.push_back(c);
        }

        while (!dq.empty()) {
            char c = dq.front();
            dq.pop_front();
            cout << c;
        }
        cout << endl;
    }

    return 0;
}