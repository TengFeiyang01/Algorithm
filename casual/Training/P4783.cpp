#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int mod = 1e9 + 7;

i64 qpow(i64 x, i64 y) {
    i64 res = 1;
    for (; y; y /= 2, x = x * x % mod)
        if (y & 1)
            res = res * x % mod;
    return res;
}

// 矩阵求逆
void solve() {
    int n;
    std::cin >> n;
    std::vector a(n, std::vector<i64>(n * 2));
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		std::cin >> a[i][j];
    	}
        a[i][i + n] = 1;
    }
    // 构造 (A, I) 得到 (I, A^-1)
    for (int i = 0; i < n; ++i) {
    	int r = i;
    	for (int k = i; k < n; ++k) {
    		if (a[k][i]) {
    			r = k;
    			break;
    		}
    	}
    	if (r != i) {
    		std::swap(a[i], a[r]);
    	}
    	if (!a[i][i]) {
    		std::cout << "No Solution\n";
    		return;
    	}
        // 计算乘法逆元
    	i64 x = qpow(a[i][i], mod - 2);
    	for (int k = 0; k < n; ++k) {
    		if (k == i) continue;
    		int t = a[k][i] * x % mod;
    		for (int j = i; j < 2 * n; ++j) {
    			a[k][j] = ((a[k][j] - t * a[i][j]) % mod + mod) % mod;
    		}
    	}
    	for (int j = 0; j < 2 * n; ++j) {
    		a[i][j] = (a[i][j] * x % mod);
    	}
    }
    for (int i = 0; i < n; ++i) {
    	for (int j = n; j < n * 2; ++j) {
    		std::cout << a[i][j] << " \n"[j == 2 * n - 1];
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
