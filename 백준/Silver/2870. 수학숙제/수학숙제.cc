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

    vector<string> v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        s += ' ';

        string k = "";
        for (int j = 0; j < s.size(); j++) {
            if (s[j] >= '0' && s[j] <= '9') {
                if (k.size() == 0 && s[j] == '0' && s[j + 1] >= '0' && s[j + 1] <= '9') continue;
                k += s[j];
            }
            else if (k.size()) {
                v.push_back(k);
                k = "";
            }
        }
    }

    sort(v.begin(), v.end(), [](string a, string b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });

    for (auto e : v) cout << e << endl;

    return 0;
}