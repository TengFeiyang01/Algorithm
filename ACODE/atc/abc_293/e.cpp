#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

ll a, x, mod;
int qpow(int x, int y) {
    int res = 1;
    for (; y; y /= 2, x = x * x % mod)
        if (y & 1)
            res = res * x % mod;
    return res;
}

int calc(int p, int k) {
    if (k == 0) {
        return 1LL;
    } else if (k % 2 == 0) {
        int x = calc(p, k - 1);
        return (p % mod * x % mod + 1) % mod;
    } else {
        int x = calc(p, k / 2), y = qpow(p, (k / 2) + 1);
        return x % mod * ((1 + y) % mod) % mod;
    }
}


void solve() {
    std::cin >> a >> x >> mod;
    std::cout << (calc(a, x) - qpow(a, x) + mod) % mod;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}













// #include <iostream>
// #include <vector>
// using namespace std;
// using ll = long long;

// vector<vector<ll>> mat_mul(vector<vector<ll>> a, vector<vector<ll>> b, ll mod) {
// 	// 行列乗算
// 	int n = a.size();
// 	vector<vector<ll>> res(n, vector<ll>(n));
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			for (int k = 0; k < n; k++) {
// 				res[i][j] += a[i][k] * b[k][j];
// 				res[i][j] %= mod;
// 			}
// 		}
// 	}
// 	return res;
// }

// vector<vector<ll>> mat_pow(vector<vector<ll>> a, ll b, ll mod) {
// 	// Matrix exponentiation
// 	int n = a.size();
// 	vector<vector<ll>> res(n, vector<ll>(n));
// 	for (int i = 0; i < n; i++) res[i][i] = 1;
// 	while (b) {
// 		if (b & 1) res = mat_mul(res, a, mod);
// 		a = mat_mul(a, a, mod);
// 		b >>= 1;
// 	}
// 	return res;
// }

// int main() {
// 	ll a, x, m;
// 	cin >> a >> x >> m;
// 	vector<vector<ll>> f = { {a,1},{0,1} };
// 	vector<vector<ll>> g = mat_pow(f, x, m);
// 	cout << g[0][1] << '\n';
// }
