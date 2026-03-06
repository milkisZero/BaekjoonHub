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

    vector<char> v;
    while (n) {
        if (n & 1) {
            n *= 2;
            v.push_back('/');
        }
        else if (n & 2) {
            n -= 2;
            v.push_back('+');
        }
        else {
            n /= 2;
            v.push_back('*');
        }
    }

    if (v.size() > 99) cout << -1;
    else {
        cout << v.size() << endl;
        while (!v.empty()) {
            cout << '[' << v.back() << ']' << sp;
            v.pop_back();
        }
    }

    return 0;
}