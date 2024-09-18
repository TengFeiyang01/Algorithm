#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, s = 0, min_lowbit = inf, idx = -1;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	s += a[i];
    	int lb = a[i] & -a[i];
    	if (lb < min_lowbit) {
    		min_lowbit = lb;
    		idx = i;
    	}
    }
    s /= min_lowbit;

    if (s % 2) {
    	std::cout << "0\n";
    	return;
    } 

   	std::vector<bool> f(s + 1);
   	f[0] = true;

   	for (int x : a) {
        x /= min_lowbit;
        for (int j = s; j >= x; --j) {
            f[j] = f[j] || f[j - x];
        }
    }

   	if (!f[s / 2]) {
   		std::cout << "0\n";
   	} else {
   		std::cout << 1 << "\n";
   		std::cout << idx + 1 << "\n";
   	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
