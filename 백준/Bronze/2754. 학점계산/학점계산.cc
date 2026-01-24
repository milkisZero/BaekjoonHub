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

    map<string, string> mp;
    mp["A+"] = "4.3";
    mp["A0"] = "4.0";
    mp["A-"] = "3.7";
    mp["B+"] = "3.3";
    mp["B0"] = "3.0";
    mp["B-"] = "2.7";
    mp["C+"] = "2.3";
    mp["C0"] = "2.0";
    mp["C-"] = "1.7";
    mp["D+"] = "1.3";
    mp["D0"] = "1.0";
    mp["D-"] = "0.7";
    mp["F"] = "0.0";

    string s;
    cin >> s;
    cout << mp[s];

    return 0;
}