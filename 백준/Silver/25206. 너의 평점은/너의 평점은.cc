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

    string a;
    double b;
    string c;

    double cnt = 0;
    double cnt2 = 0;

    map<string, double> mp = {
        {"A+", 4.5},
        {"A0", 4.0},
        {"B+", 3.5},
        {"B0", 3.0},
        {"C+", 2.5},
        {"C0", 2.0},
        {"D+", 1.5},
        {"D0", 1.0},
        {"F", 0.0}};

    while (cin >> a >> b >> c) {
        if (c == "P") continue;

        cnt += b;
        cnt2 += b * mp[c];
    }

    cout << cnt2 / cnt;

    return 0;
}