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

    auto res = [](string k) {
        if (k.empty()) k = "YODA";
        else {
            size_t st = k.find_first_not_of('0');
            k = (st == string::npos ? "0" : k.substr(st));
        }
        return k;
    };

    cout << res(aa) << endl;
    cout << res(bb);

    return 0;
}