#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

#ifndef ONLINE_JUDGE
#define debug(x) \
  cerr << __FILE__ ":" << __LINE__ << ": (" #x ") = " << x << "\n"
#else
#define debug(...)
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti += 1) {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        for (auto &si: s) { cin >> si; }
        int k = 0;
        vector id(n, vector<int>(m, -1));
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                if (s[i][j] == '*') { id[i][j] = k++; }
            }
        }
        vector<pair<int, int>> checks;
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                if (s[i][j] == '*') { continue; }
                pair<int, int> check = {0, s[i][j] - '0'};
                for (int di = -1; di <= 1; di += 1) {
                    for (int dj = -1; dj <= 1; dj += 1) {
                        int ti = i + di, tj = j + dj;
                        if (ti < 0 or ti >= n or tj < 0 or tj >= m or s[ti][tj] != '*') {
                            continue;
                        }
                        check.first |= 1 << id[ti][tj];
                    }
                }
                checks.push_back(check);
            }
        }
        int count = 0;
        for (int i = 0; i < (1 << k) and count < 2; i += 1) {
            bool ok = true;
            for (auto [x, y]: checks) {
                if (__builtin_popcount(i & x) != y) {
                    ok = false;
                    break;
                }
            }
            count += ok;
        }
        if (count == 2) {
            cout << "Multiple\n";
        } else {
            cout << "Single\n";
        }
    }
}