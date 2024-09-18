#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::set<int> st;

    std::vector<i64> a(n), b(m);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	st.insert(a[i]);
    	st.insert(a[i] + 1);
    }
    for (int i = 0; i < m; ++i) {
    	std::cin >> b[i];
    	st.insert(b[i]);
    	st.insert(b[i] + 1);
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

	int l = 0, r = inf;
	while (l < r) {
		int mid = l + r >> 1;
		int x = std::upper_bound(a.begin(), a.end(), mid) - a.begin();
		int y = m - (std::lower_bound(b.begin(), b.end(), mid) - b.begin());
		if (x >= y) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}	
	std::cout << l;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
