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

    vector<ll> stk;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ')') {
            ll tmp = 0;
            while (stk.back() != '(') {
                if (stk.back() <= 0)
                    tmp += -stk.back();
                else tmp++;
                stk.pop_back();
            }
            stk.pop_back();

            tmp *= (stk.back() - '0');
            stk.pop_back();

            stk.push_back(-tmp);
        }
        else stk.push_back(s[i]);
    }

    ll cnt = 0;
    while (!stk.empty()) {
        if (stk.back() <= 0)
            cnt += -stk.back();
        else cnt++;
        stk.pop_back();
    }

    cout << cnt;

    return 0;
}