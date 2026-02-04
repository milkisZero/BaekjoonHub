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

    vector<char> stk;
    for (int i = 0; i < s.size(); i++) {
        stk.push_back(s[i]);

        if (stk.size() >= 4) {
            string tmp;
            for (auto iter = stk.end() - 4; iter != stk.end(); iter++) tmp += *iter;
            if (tmp == "PPAP") {
                stk.erase(stk.end() - 4, stk.end());
                stk.push_back('P');
            }
        }
    }

    if (stk.size() == 1 && stk.front() == 'P') cout << "PPAP";
    else cout << "NP";

    return 0;
}