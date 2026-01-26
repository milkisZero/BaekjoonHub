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

    ll t;
    cin >> t;

    set<string> st;
    while (t--) {
        string s;
        string move;
        cin >> s >> move;

        if (move == "enter") st.insert(s);
        else st.erase(s);
    }

    for (auto iter = st.rbegin(); iter != st.rend(); iter++) {
        cout << *iter << endl;
    }

    return 0;
}