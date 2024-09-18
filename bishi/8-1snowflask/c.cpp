#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using namespace std;

int collexMax(vector<vector<int>> mat) {
    int n = mat.size();
    vector<vector<int>> f(n + 1, vector<int>(n + 1, INT_MIN));
    f[1][1] = mat[0][0];
    for (int t = 1; t < n * 2 - 1; t++) {
        for (int j = min(t, n - 1); j >= max(t - n + 1, 0); j--) {
            for (int k = min(t, n - 1); k >= j; k--) {
                if (mat[t - j][j] < 0 || mat[t - k][k] < 0) {
                    f[j + 1][k + 1] = INT_MIN;
                } else {
                    f[j + 1][k + 1] = max({f[j + 1][k + 1], f[j + 1][k], f[j][k + 1], f[j][k]}) +
                                      mat[t - j][j] + (k != j ? mat[t - k][k] : 0);
                }
            }
        }
    }
    return max(f[n][n], 0);
}


void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	cout << collexMax(a);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
