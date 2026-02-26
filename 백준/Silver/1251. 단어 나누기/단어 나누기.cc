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

    vector<string> v;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size()-1; j++) {
            string a = s.substr(0, i + 1);
            string b = s.substr(i + 1, j - i);
            string c = s.substr(j + 1, s.size() - j - 1);

            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());

            v.push_back(a + b + c);
        }
    }

    sort(v.begin(), v.end());

    cout << v[0];

    return 0;
}