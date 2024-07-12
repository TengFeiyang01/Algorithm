#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> A(n);
    int mx = 0, mn = 10000;
    for (int i = 0; i < n; ++i) {
    	std::cin >> A[i];
    	mx = std::max(mx, A[i]);
    	mn = std::min(mn, A[i]);
    }
    std::sort(A.begin(), A.end());
    for (int i = mx; i >= mn; --i) {
    	if (A.back() != i) {
    		std::cout << i << "\n";
    		return;
    	} 
    	A.pop_back();
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}