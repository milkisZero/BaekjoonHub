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
    while (getline(cin, s)) {
        if (s == ".") break;

        bool check = 0;
        vector<char> stk;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[') stk.push_back(s[i]);
            else if (s[i] == ')') {
                if (!stk.empty() && stk.back() == '(') stk.pop_back();
                else {
                    check = 1;
                    break;
                }
            }
            else if (s[i] == ']') {
                if (!stk.empty() && stk.back() == '[') stk.pop_back();
                else {
                    check = 1;
                    break;
                }
            }
        }
        if (check || !stk.empty()) cout << "no" << endl;
        else cout << "yes" << endl;
    }

    return 0;
}