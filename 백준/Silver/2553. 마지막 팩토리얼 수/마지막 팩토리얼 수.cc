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

    ll k = 1;
    for (int i = 1; i <= n; i++) {
        k *= i;
        k %= 10000000;
        while (k % 10 == 0) {
            k /= 10;
        }
    }

    cout << k % 10;

    return 0;
}