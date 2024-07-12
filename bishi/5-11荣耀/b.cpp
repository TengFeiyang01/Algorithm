#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using cplx = std::complex<double>;

void solve() {
	int n, m;
	std::cin >> n >> m;   
	std::vector<cplx> a(n); 
	std::vector<std::vector<cplx>> b(m, std::vector<cplx>(n));
	for (int i = 0; i < n; ++i) {
		double real, imag;
		std::cin >> real >> imag;
		a[i] = cplx(real, imag);
	} 
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i) {
			double real, imag;
			std::cin >> real >> imag;
			b[j][i] = cplx(real, imag);
		} 
	}
	double mn = 1e15;
	int ans = -1;
	for (int i = 0; i < m; ++i) {
	 	cplx cur = 0;
		for (int j = 0; j < n; ++j) {
			cur += std::conj(a[j]) * b[i][j];
		}
		if (abs(cur) < mn) {
			mn = abs(cur);
			ans = i;
		}
	}
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
