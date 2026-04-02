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

bool isPalin(string s, int l, int r) {
    while (l < r && s[l] == s[r]) l++, r--;
    return l >= r;
}

int main() {
    fastio;

    ll n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        int l = 0, r = s.size() - 1;
        while (l < r && s[l] == s[r]) l++, r--;

        if (l >= r) {
            cout << 0 << endl;
            continue;
        }

        if (isPalin(s, l + 1, r) || isPalin(s, l, r - 1)) cout << 1 << endl;
        else cout << 2 << endl;
    }

    return 0;
}