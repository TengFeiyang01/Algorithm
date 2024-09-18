#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

int get(std::vector<int> &a) {
	int n = a.size(), i = 0, ans = 0;
	while (i < n) {
		int j = i;
		while (j + 1 < n and a[j + 1] == a[i]) {
			j += 1;
		}
		ans = std::max(ans, j - i + 1);
		i = j + 1;
	}
	return ans;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::set<int> st;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	st.insert(a[i]);
    }
    
    int pre = get(a), ans = 0;

    for (int k : st) {
    	std::vector<int> b;
    	for (int i = 0; i < n; ++i) {
    		if (a[i] != k) {
    			b.push_back(a[i]);
    		}
    	}
    	ans = std::max(ans, get(b) - pre);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
