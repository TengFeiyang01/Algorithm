#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int M = 1000;
const int mod = 998244353;
int fac[1000001][3];
int mx = 1000001;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i];
    }

    fac[1][0] = fac[1][1] = fac[1][2] = 1;
    std::vector<int> prime;
    std::bitset<1000010> st; 
    
    for (int i = 2; i <= mx; ++i) {
    	if (!st[i]) {
    		prime.push_back(i);
    		fac[i][0] = fac[i][1] = 1;
    		fac[i][2] = i;
    	}
    	for (int p : prime) {
    		if (i * p > mx) break;
    		int tmp = i * p;
    		st[tmp] = 1;
    		// fac[tmp] = fac[i];
            fac[tmp][0] = fac[i][0];
            fac[tmp][1] = fac[i][1];
            fac[tmp][2] = fac[i][2];
    		fac[tmp][0] *= p;
            if (fac[tmp][0] > fac[tmp][1]) {
                fac[tmp][0] ^= fac[tmp][1] ^= fac[tmp][0] ^= fac[tmp][1];
            }
            if (fac[tmp][1] > fac[tmp][2]) {
                fac[tmp][1] ^= fac[tmp][2] ^= fac[tmp][1] ^= fac[tmp][2];
            }    		
            if (i % p == 0) break; 
    	}
    }

    std::vector f(M, std::vector<int>(M));
    for (int i = 0; i < M; ++i) f[i][0] = f[0][i] = i;
    for (int i = 1; i < M; ++i) {
    	for (int j = 1; j < M; ++j) {
    		f[j][i] = f[i][j] = std::__gcd(j % i, i);
    	}
    }
    auto gcd = [&](int x, int y) {
    	int g = 1;
    	for (int i = 0; i < 3; ++i) {
    		int tmp = (fac[x][i] > M) ? 
    					(y % fac[x][i] ? 1 : fac[x][i]) :
    					f[fac[x][i]][y % fac[x][i]];
    		y /= tmp;
    		g *= tmp;
    	}
    	return g;
    };

    for (int i = 0; i < n; ++i) {
    	int now = 1, ans = 0;
    	for (int j = 0; j < n; ++j) {
    		now = 1LL * now * (i + 1) % mod;
    		ans = (ans + 1LL * gcd(a[i], b[j]) * now % mod) % mod;
    	}
    	std::cout << ans << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
