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
        ll cnt = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') cnt4++;
            else if (s[i] >= 'a') cnt++;
            else if (s[i] >= 'A') cnt2++;
            else cnt3++;
        }
        cout << cnt << sp << cnt2 << sp << cnt3 << sp << cnt4 << endl;
    }

    return 0;
}