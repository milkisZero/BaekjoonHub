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

set<string> st;

int main() {
    fastio;

    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        st.insert(s);
    }

    ll cnt = 0;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
 
        if(st.find(s) != st.end()) cnt++;
    }
    cout << cnt;

    return 0;
}