#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    i64 mx, ds = 0, carry = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	mx = std::max(mx, a[i]);
    	for (i64 x = a[i]; x; x /= 10) {
    		ds += x % 10;
    	}
    }
    for (i64 pow = 10; pow <= 2 * mx; pow *= 10) {
    	std::sort(a.begin(), a.end(), [&](auto x, auto y){
    		return x % pow < y % pow;
    	});
    	int j = n - 1;
    	for (i64 x : a) {
    		while (j >= 0 and x % pow + a[j] % pow >= pow) {
    			--j;
    		}
    		carry += n - 1 - j;
    	}
    }
    std::cout << (ds * n * 2 - carry * 9);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
