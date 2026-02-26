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
    getline(cin, s);

    string a;
    int c = 0;
    for (int i = 0; i < s.size(); i++) {
        if (c && s[i] != '>') {
            a += s[i];
            continue;
        }

        if (s[i] == '>') {
            a += s[i];
            cout << a;
            a = "";
            c = 0;
        }
        else if (s[i] == '<' || s[i] == ' ') {
            reverse(a.begin(), a.end());
            cout << a;
            cout << s[i];
            a = "";

            if (s[i] == '<') c = 1;
        }
        else {
            a += s[i];
        }
    }

    if (s[s.size() - 1] != '>') {
        reverse(a.begin(), a.end());
        cout << a;
    }

    return 0;
}