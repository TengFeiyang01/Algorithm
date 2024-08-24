#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int mod = 1e9 + 7;

void solve() {
    int n, k, t;
    cin >> n >> k >> t;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int P = 100 * n;
    int UP = P * 2;

    vector<vector<i64>> prev(k + 1, vector<i64>(UP + 1, 0));
    prev[0][P] = 1;

    for (int i = 0; i < n; ++i) {
        vector<vector<i64>> next(k + 1, vector<i64>(UP + 1, 0));

        int v = arr[i];
        for (int j = 0; j <= k; ++j) {
            for (int s = 0; s <= UP; ++s) {
                if (prev[j][s] == 0) continue;
                if (j < k && s - v >= 0) {
                    next[j + 1][s - v] = (next[j + 1][s - v] + prev[j][s]) % mod;
                }
                if (s + v <= UP) {
                    next[j][s + v] = (next[j][s + v] + prev[j][s]) % mod;
                }
            }
        }
        prev.swap(next);
    }

    i64 ans = 0;
    for (int i = 0; i <= k; ++i) {
        for (int j = P; j <= min(UP, P + t); ++j) {
            ans = (ans + prev[i][j]) % mod;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
