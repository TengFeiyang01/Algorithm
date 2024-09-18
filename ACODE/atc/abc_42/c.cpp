#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(10);
    for (int i = 0; i < k; ++i) {
    	int x;
    	std::cin >> x;
    	a[x]++;
    }

    for (int i = n; i <= 1000000; ++i) {
    	int ok = 1;
    	for (int t = i; t; t /= 10) {
    		if (a[t % 10]) {
    			ok = 0;
    		}
    	}
    	if (ok) {
    		std::cout << i << "\n";
    		return;
    	}
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
