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

    string s;
    cin >> s;
    vector<ll> v(26, 0);
    for (int i = 0; i < s.size(); i++) {
        v[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        cout << v[i] << ' ';
    }

    return 0;
}