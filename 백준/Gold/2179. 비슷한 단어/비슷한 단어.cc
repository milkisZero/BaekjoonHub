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

    ll n;
    cin >> n;

    unordered_map<string, vector<ll>> ump;
    vector<string> v(n);
    set<string> st;
    int max_leng = 0;
    string part = "";
    int idx = n;

    for (int i = 0; i < n; i++) {
        cin >> v[i];

        if (st.find(v[i]) != st.end()) continue;
        st.insert(v[i]);

        string tmp = "";
        for (int j = 0; j < v[i].size(); j++) {
            tmp += v[i][j];

            ump[tmp].push_back(i);
            if (ump[tmp].size() >= 2) {
                if (max_leng == j + 1 && ump[tmp][0] < idx) {
                    part = tmp;
                    idx = ump[tmp][0];
                }
                else if (max_leng < j + 1) {
                    max_leng = j + 1;
                    part = tmp;
                    idx = ump[tmp][0];
                }
            }
        }
    }

    cout << v[ump[part][0]] << endl
         << v[ump[part][1]];

    return 0;
}