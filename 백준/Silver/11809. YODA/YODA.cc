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

    string a, b;
    cin >> a >> b;

    if (a.size() < b.size()) {
        a = string((b.size() - a.size()), '0') + a;
    }
    else {
        b = string((a.size() - b.size()), '0') + b;
    }

    string aa = "", bb = "";
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > b[i]) aa += a[i];
        else if (a[i] < b[i]) bb += b[i];
        else {
            aa += a[i];
            bb += b[i];
        }
    }

    if (aa.empty()) aa = "YODA";
    else {
        size_t st = aa.find_first_not_of('0');
        aa = (st == string::npos ? "0" : aa.substr(st));
    }

    if (bb.empty()) bb = "YODA";
    else {
        size_t st = bb.find_first_not_of('0');
        bb = (st == string::npos ? "0" : bb.substr(st));
    }

    cout << aa << endl;
    cout << bb;

    return 0;
}