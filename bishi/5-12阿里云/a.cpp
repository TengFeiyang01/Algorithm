#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::vector<int> a(n + 1), b(n + 1);
    std::cin >> s;
    char x = '0', y = '1';
    for (int i = 0; i < n; ++i) {
    	a[i + 1] = a[i];
    	b[i + 1] = b[i];
    	if (s[i] != x) {
    		a[i + 1]++;
    	}
    	if (s[i] != y) {
    		b[i + 1]++;
    	} 
    	x ^= 1;
    	y ^= 1;
    }
    for (int i = 0; i < q; ++i) {
    	int l, r;
    	std::cin >> l >> r;
    	std::cout << std::min(a[r] - a[l - 1], b[r] - b[l - 1]) << "\n";
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
