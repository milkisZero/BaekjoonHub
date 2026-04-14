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

ll psum[303][303];

int main() {
    fastio;

    ll n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ll tmp;
            cin >> tmp;
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + tmp;
        }
    }

    ll maxi = -1000;
    for (int K = 1; K <= n; K++) {                 // 정사각형 크기
        for (int r = 1; r + K - 1 <= n; r++)       // 좌상단 행
            for (int c = 1; c + K - 1 <= n; c++) { // 좌상단 열
                ll sum = psum[r + K - 1][c + K - 1] - psum[r - 1][c + K - 1] - psum[r + K - 1][c - 1] + psum[r - 1][c - 1];
                maxi = max(maxi, sum);
            }
    }

    cout << maxi;

    return 0;
}